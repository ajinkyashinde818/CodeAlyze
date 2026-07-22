import os
import uuid
from flask import Blueprint, request, jsonify, current_app

from predictor import predict, analyze_features
from utils import detect_language, detect_language_from_code, is_valid_code, record_analysis, get_analytics, export_analytics_csv, export_analytics_json

api = Blueprint("api", __name__)

UPLOAD_FOLDER = os.path.join(os.path.dirname(__file__), "uploads")
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

ALLOWED_EXT = {".c", ".cpp", ".cc", ".cxx", ".h", ".hpp", ".java", ".py"}


@api.route("/health", methods=["GET"])
def health():
    return jsonify({"status": "ok", "service": "CodeAlyze API"}), 200


@api.route("/analyze", methods=["POST"])
def analyze():
    data = request.get_json(silent=True)
    if not data or "code" not in data:
        return jsonify({"error": "Missing 'code' field in JSON body"}), 400

    code = data["code"]
    if not is_valid_code(code):
        return jsonify({"error": "Empty or invalid code"}), 400

    filename = data.get("filename", "source.txt")
    language = data.get("language", None)
    if language:
        if language not in ("C", "C++", "Java", "Python"):
            return jsonify({"error": f"Unsupported language: {language}"}), 400
    else:
        language = detect_language(filename)
        if language == "Unknown":
            language = detect_language_from_code(code)

    try:
        label, confidence, raw_score = predict(code)
        features = analyze_features(code)
    except Exception as e:
        return jsonify({"error": f"Prediction failed: {str(e)}"}), 500

    record_analysis(language, label, confidence, len(code))

    return jsonify({
        "prediction": label,
        "confidence": confidence,
        "raw_score": raw_score,
        "language": language,
        "features": features,
        "note_heuristics": "Feature detections are rule-based heuristics and may not reflect actual model decision factors.",
        "suggestion": "For model-based explanations, consider future updates with LIME or SHAP integration.",
    })


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

    if not is_valid_code(code):
        return jsonify({"error": "File is empty or unreadable"}), 400

    language = detect_language(file.filename)
    if language == "Unknown":
        language = detect_language_from_code(code)

    try:
        label, confidence, raw_score = predict(code)
        features = analyze_features(code)
    except Exception as e:
        return jsonify({"error": f"Prediction failed: {str(e)}"}), 500

    record_analysis(language, label, confidence, len(code))

    return jsonify({
        "filename": file.filename,
        "prediction": label,
        "confidence": confidence,
        "raw_score": raw_score,
        "language": language,
        "features": features,
        "note_heuristics": "Feature detections are rule-based heuristics and may not reflect actual model decision factors.",
        "suggestion": "For model-based explanations, consider future updates with LIME or SHAP integration.",
    })


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

