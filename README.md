# CodeAlyze

CodeAlyze is a Flask and static-frontend app that estimates whether C, C++, Java, or Python source code resembles AI-generated or human-written code.

The current checked-in model is a real scikit-learn pipeline, but the original training dataset is not included in this repository. Treat predictions as estimates, not proof of authorship.

## Current Inference Pipeline

1. The frontend sends code to `POST /api/analyze`.
2. Flask validates the submitted code and language.
3. `backend/predictor.py` loads `backend/models/codealyze_model.pkl` once per process.
4. The model applies character-level TF-IDF features and a linear classifier.
5. The API returns the predicted class, uncalibrated score, model version, language, and heuristic feature flags.

Verified model artifact:

- `TfidfVectorizer(analyzer="char_wb", ngram_range=(3, 5), lowercase=False, max_features=250000)`
- `LinearSVC(max_iter=5000, random_state=42)`
- Classes: `ai`, `human`

## Problem Statement

Instructors increasingly receive student code whose origin is unclear. CodeAlyze explores whether a supervised classifier can estimate whether a submitted program resembles AI-generated or human-written examples from its training data. It is a decision-support and learning exercise, not an accusation tool.

## Objectives and Scope

In scope:

- A working end-to-end inference API for four languages.
- A transparent pipeline that a student can explain line by line.
- Honest reporting of dataset and evaluation status.
- Reproducible dataset audit, training, and evaluation scripts.

Out of scope:

- Proving authorship or detecting academic misconduct.
- Real-time monitoring, plagiarism detection, or watermark detection.
- Multi-user accounts, billing, or cloud infrastructure.

## Architecture and Data Flow

```text
Browser (HTML/CSS/vanilla JS)
        |
        | POST /api/analyze  { language, code }
        v
Flask app (backend/app.py, backend/routes.py)
        |
        |-- validate code type, emptiness, size limit, supported language
        |-- backend/predictor.py::predict
        |       -> loads models/codealyze_model.pkl once per process
        |       -> model.predict([code])
        |       -> model.decision_function([code])
        |-- backend/predictor.py::analyze_features (rule-based heuristics only)
        |-- backend/utils.py::record_analysis (counts only, never source code)
        v
JSON response -> frontend/script.js renders the result panel
```

Components, kept deliberately distinct:

| Component | Responsibility |
|---|---|
| `TfidfVectorizer` + `LinearSVC` | The trained ML classifier. This produces the prediction. |
| `analyze_features` | Static regex checks. Display-only indicators, not model explanations. |
| Flask blueprint | Input validation, orchestration, and response shaping. |
| Frontend | Presentation of whatever the API actually returns. |

## Important Limitations

- The dataset claimed in older documentation is not present in this checkout.
- Existing model metrics cannot be independently verified without the original data or a holdout set.
- The returned score is derived from an uncalibrated SVM margin and is not a probability.
- Very short, obfuscated, mixed-origin, or out-of-distribution code can be unreliable.
- Submitted source code is not stored. Only language, prediction, score, and length are recorded.

## Machine-Learning Methodology

The pipeline converts each program into character n-grams, then learns a linear decision boundary between the two label classes.

- **Character n-grams** are short overlapping substrings of the source text, taken with `char_wb` so word boundaries are respected. They capture punctuation style, indentation, naming style, and syntax rhythm without parsing the code.
- **TF-IDF weighting** increases the influence of distinctive patterns and decreases the influence of patterns that appear in almost every file.
- **LinearSVC** is a linear support-vector classifier. It finds a hyperplane separating AI-like from human-like examples in the TF-IDF feature space.
- The returned score is `sigmoid(abs(decision_function))`. This is a **margin-magnitude display score, not a calibrated probability**. A calibrated model plus documented calibration quality would be required before calling any output a probability.


## Demonstration Workflow

1. Start the backend with `cd backend` and `python app.py`.
2. Open `http://127.0.0.1:5000`.
3. On the landing page, explain the problem: estimating whether code resembles AI-generated or human-written examples.
4. Scroll to the analyzer. Load a labelled sample, or paste your own C, C++, Java, or Python code.
5. Select the language and click **Analyze Code**. Point out the loading state.
6. In the result panel, identify the predicted class, language, model version, score method, raw margin, and the warning that the score is not a probability.
7. Explain that the "Rule-based indicators" are shown for discussion, not model explanations.
8. Scroll to the model section. Point out the status strip: backend connectivity, model-artifact state, and evaluation status are reported separately. Explain that evaluation metrics are pending because the dataset is not present in this checkout.
9. Mention the reproducible audit, training, and evaluation scripts as the path to verified improvement.

See [TEACHER_DEMO_GUIDE.md](TEACHER_DEMO_GUIDE.md) for a ready-to-read presentation script.

## Documentation

- [AUDIT_REPORT.md](AUDIT_REPORT.md) — audit findings and remediation record.
- [MODEL_CARD.md](MODEL_CARD.md) — model card for the checked-in artifact.
- [TEACHER_DEMO_GUIDE.md](TEACHER_DEMO_GUIDE.md) — faculty demonstration walkthrough.

## Setup

```bash
cd backend
pip install -r requirements.txt
python app.py
```

Then open:

```text
http://127.0.0.1:5000
```

For production, serve the Flask app with a WSGI server such as gunicorn:

```bash
cd backend
gunicorn app:app
```

## API

Health:

```bash
curl http://127.0.0.1:5000/api/health
```

Readiness:

```bash
curl http://127.0.0.1:5000/api/ready
```

Analyze:

```bash
curl -X POST http://127.0.0.1:5000/api/analyze ^
  -H "Content-Type: application/json" ^
  -d "{\"language\":\"Python\",\"code\":\"def add(a, b): return a + b\"}"
```

Supported languages are `C`, `C++`, `Java`, and `Python`.

Model information, read live from the artifact and committed audit reports:

```bash
curl http://127.0.0.1:5000/api/model-info
curl http://127.0.0.1:5000/api/dataset-audit
```

Dashboard usage counts and exports (metadata only, no stored source code):

```bash
curl http://127.0.0.1:5000/api/admin/stats
curl "http://127.0.0.1:5000/api/admin/stats/export?format=csv"
curl "http://127.0.0.1:5000/api/admin/stats/export?format=json"
```

### `/api/analyze` response fields

| Field | Meaning |
|---|---|
| `prediction` | `AI Generated` or `Human Written` |
| `class_id` | Raw class label from the artifact: `ai` or `human` |
| `confidence`, `confidence_score` | Uncalibrated margin-derived display score (0-100), **not** a probability |
| `confidence_method` | Identifies the score as an uncalibrated SVM-margin score |
| `raw_score`, `raw_margin` | Raw `decision_function` value |
| `language` | Resolved language |
| `model_version` | Version label reported by the artifact |
| `warning` | Explicit statement that the score is not a probability |
| `features` | Rule-based heuristic detections, kept separate from the model prediction |
| `note_heuristics` | States that heuristics are not formal model explanations |

Error responses use explicit status codes: `400` for validation failures, `503` when the model is unavailable, and `500` for unexpected inference errors.


Environment variables:

- `PORT`: Flask port when running `python backend/app.py`.
- `FLASK_DEBUG`: set to `1` for local debug mode.
- `CODEALYZE_MAX_CODE_CHARS`: maximum code payload size, default `200000`.
- `CODEALYZE_MODEL_VERSION`: optional model version label.

The frontend uses same-origin API requests by default. A deployment can override this by defining `window.CODEALYZE_API_BASE_URL` before `frontend/script.js` loads.

## Dataset Status

No dataset directory is present in this checkout, so no sample counts, duplicate rates, label quality, or leakage measurements can be verified. The committed audit artifact records that the dataset root was absent.

```bash
python scripts/audit_dataset.py --dataset dataset
```

Outputs:

- `reports/dataset_audit.json`
- `reports/DATASET_AUDIT_REPORT.md`

The script reports counts by label/language, empty and short files, exact duplicates, normalized duplicates, and train/test overlap where split directories are present. It never modifies or deletes dataset files.

## Training

Training is separate from serving. Expected dataset layout can use label directories such as:

```text
dataset/
  ai/
    python/
    java/
  human/
    python/
    java/
```

Train a reproducible baseline:

```bash
python scripts/train_model.py --dataset dataset --model logreg
```

Alternative:

```bash
python scripts/train_model.py --dataset dataset --model linearsvc
```

Outputs:

- `backend/models/codealyze_model.pkl`
- `reports/training_metrics.json`

Do not replace the production artifact unless the dataset audit and holdout metrics support the change.


## Evaluation Status

**Evaluation pending dataset verification.**

No trustworthy accuracy, precision, recall, F1, or confusion-matrix value is claimed for the checked-in artifact. The UI reports metrics only when a real `reports/evaluation_metrics.json` artifact exists:

```bash
python scripts/evaluate_model.py --dataset path/to/holdout --model backend/models/codealyze_model.pkl
```

Output:

- `reports/evaluation_metrics.json`

Keep holdout data separate from training, model selection, and threshold tuning.

## Ethical Considerations

- A prediction is a statistical estimate. It cannot establish who wrote a program.
- Using this tool as evidence of misconduct would be an unfair use of an unvalidated model.
- The model may be sensitive to formatting, boilerplate, comments, and course templates rather than genuine authorship signals.
- Students should be informed if such tooling is used in any academic setting.

## Future Improvements

- Acquire and publish a documented, licensed dataset.
- Run the dataset audit, then build a leakage-resistant grouped split.
- Compare `logreg` and `linearsvc` on a real holdout and keep the better model only if metrics justify it.
- Calibrate scores, or keep them explicitly labelled as uncalibrated.
- Add SHAP or LIME analysis only after a verified evaluation exists.
- Add per-language evaluation reporting.

## Tests

```bash
python -m unittest discover -s tests
```

The API tests cover valid input, empty input, missing fields, invalid language, oversized input, Unicode input, readiness, model-info reporting, dashboard stats, exports, page serving, and missing-model behavior. Additional tests assert that dataset and evaluation status never fabricate metrics.

