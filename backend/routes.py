import os
import uuid
from flask import Blueprint, request, jsonify, current_app

from predictor import (
    ModelUnavailableError,
    dataset_status,
    predict,
    analyze_features,
    model_status,
    model_info,
)
from utils import detect_language, detect_language_from_code, is_valid_code, record_analysis, get_analytics, export_analytics_csv, export_analytics_json

api = Blueprint("api", __name__)

UPLOAD_FOLDER = os.path.join(os.path.dirname(__file__), "uploads")
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

ALLOWED_EXT = {".c", ".cpp", ".cc", ".cxx", ".h", ".hpp", ".java", ".py"}
SUPPORTED_LANGUAGES = {"C", "C++", "Java", "Python"}
DEFAULT_MAX_CODE_CHARS = 200_000


def _max_code_chars() -> int:
    return int(current_app.config.get("MAX_CODE_CHARS", DEFAULT_MAX_CODE_CHARS))


def _validate_code_payload(code):
    if not isinstance(code, str):
        return "Code must be a string."
    if not is_valid_code(code):
        return "Empty or invalid code."
    if len(code) > _max_code_chars():
        return f"Code exceeds the {_max_code_chars()} character limit."
    return None


def _resolve_language(code: str, filename: str, language: str | None):
    if language:
        if language not in SUPPORTED_LANGUAGES:
            return None, f"Unsupported language: {language}"
        return language, None

    detected = detect_language(filename)
    if detected == "Unknown":
        detected = detect_language_from_code(code)
    if detected not in SUPPORTED_LANGUAGES:
        return None, "Unable to determine a supported language. Select C, C++, Java, or Python."
    return detected, None


def _prediction_response(code: str, language: str, filename: str | None = None):
    prediction = predict(code)
    features = analyze_features(code)
    record_analysis(language, prediction.label, prediction.confidence_score, len(code))

    payload = {
        "prediction": prediction.label,
        "class_id": prediction.class_id,
        "confidence": prediction.confidence_score,
        "confidence_score": prediction.confidence_score,
        "confidence_method": prediction.confidence_method,
        "raw_score": prediction.raw_margin,
        "raw_margin": prediction.raw_margin,
        "language": language,
        "model_version": prediction.model_version,
        "warning": prediction.warning,
        "features": features,
        "note_heuristics": "Feature detections are rule-based heuristics and may not reflect actual model decision factors.",
        "suggestion": "For model-based explanations, consider future updates with LIME or SHAP integration.",
    }
    if filename:
        payload["filename"] = filename
    return jsonify(payload)


@api.route("/health", methods=["GET"])
def health():
    return jsonify({"status": "ok", "service": "CodeAlyze API"}), 200


@api.route("/ready", methods=["GET"])
def ready():
    status = model_status()
    http_status = 200 if status["available"] else 503
    return jsonify({"status": "ready" if status["available"] else "not_ready", "model": status}), http_status


@api.route("/model-info", methods=["GET"])
def model_info_endpoint():
    return jsonify(model_info()), 200


@api.route("/dataset-audit", methods=["GET"])
def dataset_audit_endpoint():
    return jsonify(dataset_status()), 200


@api.route("/analyze", methods=["POST"])
def analyze():
    data = request.get_json(silent=True)
    if not data or "code" not in data:
        return jsonify({"error": "Missing 'code' field in JSON body"}), 400

    code = data["code"]
    validation_error = _validate_code_payload(code)
    if validation_error:
        return jsonify({"error": validation_error}), 400

    filename = data.get("filename", "source.txt")
    language, language_error = _resolve_language(code, filename, data.get("language"))
    if language_error:
        return jsonify({"error": language_error}), 400

    try:
        return _prediction_response(code, language)
    except ModelUnavailableError as e:
        return jsonify({"error": "Model unavailable", "detail": str(e)}), 503
    except Exception as e:
        return jsonify({"error": f"Prediction failed: {str(e)}"}), 500


@api.route("/upload", methods=["POST"])
def upload():
    if "file" not in request.files:
        return jsonify({"error": "No file provided"}), 400

    file = request.files["file"]
    if file.filename == "":
        return jsonify({"error": "Empty filename"}), 400

    ext = os.path.splitext(file.filename.lower())[1]
    if ext not in ALLOWED_EXT:
        return jsonify({"error": f"Unsupported extension: {ext}. Allowed: {', '.join(sorted(ALLOWED_EXT))}"}), 400

    safe_name = f"{uuid.uuid4().hex}{ext}"
    filepath = os.path.join(UPLOAD_FOLDER, safe_name)
    file.save(filepath)

    try:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            code = f.read()
    except Exception as e:
        return jsonify({"error": f"Failed to read file: {str(e)}"}), 500
    finally:
        # Uploaded files are only needed to read the code once. Remove the
        # temporary copy so source files are not durably stored on disk.
        try:
            os.remove(filepath)
        except OSError:
            pass

    validation_error = _validate_code_payload(code)
    if validation_error:
        return jsonify({"error": validation_error}), 400

    language, language_error = _resolve_language(code, file.filename, None)
    if language_error:
        return jsonify({"error": language_error}), 400

    try:
        return _prediction_response(code, language, filename=file.filename)
    except ModelUnavailableError as e:
        return jsonify({"error": "Model unavailable", "detail": str(e)}), 503
    except Exception as e:
        return jsonify({"error": f"Prediction failed: {str(e)}"}), 500


@api.route("/admin/stats", methods=["GET"])
def admin_stats():
    try:
        stats = get_analytics()
        return jsonify(stats), 200
    except Exception as e:
        return jsonify({"error": str(e)}), 500


@api.route("/admin/stats/export", methods=["GET"])
def admin_stats_export():
    fmt = request.args.get("format", "csv").lower()
    try:
        if fmt == "json":
            data = export_analytics_json()
            return jsonify(data), 200
        else:
            csv_data = export_analytics_csv()
            return current_app.response_class(
                csv_data,
                mimetype="text/csv",
                headers={"Content-Disposition": "attachment; filename=codealyze_analytics_export.csv"},
            )
    except Exception as e:
        return jsonify({"error": str(e)}), 500

