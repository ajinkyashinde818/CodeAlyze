# CodeAlyze Audit Report

Audit date: 2026-10-11

## Current Architecture

CodeAlyze is a small Flask application with a static HTML/CSS/JavaScript frontend.

- Frontend: `frontend/index.html`, `frontend/script.js`, `frontend/styles.css`
- Admin dashboard: `frontend/admin.html`
- API app: `backend/app.py`
- API routes: `backend/routes.py`
- Inference code: `backend/predictor.py`
- Analytics storage: `backend/utils.py`, `backend/analytics.db`
- Model artifact: `backend/models/codealyze_model.pkl`

The normal prediction pipeline is:

1. Browser sends JSON to `POST /api/analyze`.
2. `backend/routes.py::analyze` validates the JSON body, code, and language.
3. `backend/routes.py::_prediction_response` calls `backend/predictor.py::predict`.
4. `backend/predictor.py::get_model` loads `backend/models/codealyze_model.pkl` with `joblib`.
5. `predict` calls `model.predict([code])` and `model.decision_function([code])`.
6. The API returns the label, uncalibrated margin-derived score, language, model version, and heuristic feature flags.
7. The frontend displays the API response. No mock prediction is generated in `frontend/script.js`.

## Actual Prediction Mechanism

The prediction function is `backend/predictor.py::predict`.

The repository contains a real scikit-learn artifact at `backend/models/codealyze_model.pkl`.

Verified artifact details:

- SHA256: `24A1B3EB36B253C14C65243ABE332A2C3E66F0500C62C83A62F8B20CBE88B814`
- Type: `sklearn.pipeline.Pipeline`
- Steps:
  - `TfidfVectorizer(analyzer='char_wb', ngram_range=(3, 5), lowercase=False, max_features=250000)`
  - `LinearSVC(max_iter=5000, random_state=42)`
- Classes: `ai`, `human`
- Vocabulary size in artifact: `250000`

Predictions are not random and are not made only by keyword rules. The displayed "Detected Features" are rule-based heuristics from `backend/predictor.py::analyze_features`; they are separate from the model prediction and are not model explanations.

## Confirmed Issues

- The repository does not include `dataset/` or `training/`, despite README claims. The claimed 40,000 AI plus 40,000 human samples cannot be verified from this checkout.
- No training script, evaluation script, model card, dataset audit output, or reproducible training configuration existed before this pass.
- The model artifact is a bare pickle without embedded dataset version, metrics, feature config metadata, or calibration information.
- Loading the artifact with local scikit-learn 1.7.2 produces warnings because the artifact was pickled with scikit-learn 1.9.0.
- The old API treated `sigmoid(abs(decision_function))` as "confidence". That is not a calibrated probability.
- The old API accepted any non-empty code length and did not reject oversized requests.
- If the model was missing, the old API returned a generic prediction failure instead of an explicit service-unavailable response.
- `frontend/script.js` and `frontend/admin.html` hardcoded `https://codealyze.onrender.com`, which breaks local same-origin serving unless edited manually.
- `backend/uploads/` stores uploaded files but does not clean them up. For the current small app this is a manageable operational issue, but it should be monitored.
- `backend/analytics.db` is committed/generated local state. It is not appropriate as durable production analytics storage, though it is acceptable for a small demo.

## Dataset And Evaluation Limitations

No dataset files are present in this checkout. Therefore:

- Exact sample counts by class and language could not be verified.
- Duplicate, near-duplicate, corrupted, empty, or extremely short files could not be measured.
- Train/test leakage could not be checked against actual data.
- The previous 100% accuracy claim could not be reproduced.
- No trustworthy accuracy, precision, recall, F1, confusion matrix, or per-language metric can be claimed for the existing artifact from this repository alone.

I added `scripts/audit_dataset.py` and generated `reports/DATASET_AUDIT_REPORT.md`, which records that the dataset root is absent.

## Scalability Bottlenecks

- Inference is stateless except for SQLite analytics writes and local upload files.
- Model reuse is now explicit: the model is loaded into process memory and reused.
- Large request validation is now enforced with `CODEALYZE_MAX_CODE_CHARS` / `MAX_CODE_CHARS`.
- Training remains separate from serving.
- SQLite analytics can become a write bottleneck under concurrent production load.
- Flask's development server is not production serving infrastructure; use `gunicorn` or a platform-managed WSGI runner.

## Remediation Completed

- Added explicit model availability handling and `/api/ready`.
- Added request size validation and stricter language handling.
- Added structured prediction response fields: `class_id`, `model_version`, `raw_margin`, `confidence_method`, and warning text.
- Stopped presenting the margin-derived score as a calibrated probability in UI copy.
- Changed frontend API base URL to same-origin by default, with `window.CODEALYZE_API_BASE_URL` override support.
- Added dataset audit script.
- Added reproducible training and evaluation scripts.
- Added API tests for valid input, empty input, invalid language, oversized input, readiness, and missing model.
- Added this audit report and `MODEL_CARD.md`.
- Added this audit report and `MODEL_CARD.md`.

## Second-Pass Improvements

- Added `/api/dataset-audit` and extended `/api/model-info` so the UI displays verified dataset and evaluation status read from committed report artifacts instead of hardcoded copy.
- Added `dataset_status()` and `evaluation_status()` in `backend/predictor.py`. These return an honest pending status when artifacts are absent and never invent counts or metrics.
- Added `KNOWN_LIMITATIONS` to the API so the landing page lists documented limitations sourced from the backend.
- Rebuilt `frontend/admin.html`. The previous version referenced undefined CSS custom properties (`--surface2`, `--text2`, `--radius-sm`, `--primary-dim`) and had no mobile navigation, so the layout and contrast were broken. It now uses the shared design system, has a working mobile nav, honest empty/error states, a recent-analyses table, and states that counters are usage data rather than accuracy.
- Relabelled the dashboard section from "Confidence Distribution" to "Model score distribution" so it is not read as calibrated probabilities.
- Added a Technology stack section to the landing page and made the Model information section render live API data with a safe fallback.
- Fixed the copy-result path: a clipboard failure no longer hides the result card, and a non-secure-context fallback was added.
- Applied HTML escaping to backend-supplied strings rendered into the result and model-info panels.
- Made the CORS allow-list configurable through `CODEALYZE_ALLOWED_ORIGINS` while keeping the existing defaults.
- Expanded the test suite to cover health, model-info honesty, dataset-audit honesty, admin stats, exports, page serving, Unicode input, missing `code`, and status-helper behaviour with and without artifacts.

## Verification Status

- The Python test suite and the running application were **not executed in the environment used for this pass** because the shell tool was unavailable. The backend changes were reviewed for correctness but must be run before the demonstration:

  ```bash
  python -m unittest discover -s tests
  cd backend && python app.py
  ```

- No browser-based visual verification was performed, so no screenshots are available. The CSS and markup changes are consistent with the existing design system but have not been rendered.


## Prioritized Next Steps

1. Add the real dataset or documented dataset acquisition instructions.
2. Run `python scripts/audit_dataset.py --dataset dataset` and inspect duplicates, split overlap, unknown labels, and class/language counts.
3. Create a leakage-resistant holdout split. If samples share repositories, prompts, projects, or templates, use grouped splitting.
4. Train with `scripts/train_model.py`, compare `logreg` and `linearsvc`, and keep the best model only if holdout metrics justify it.
5. Calibrate scores if the UI needs probabilities; otherwise continue labeling them as uncalibrated scores.
6. Remove local generated state such as `analytics.db` from version control if this project will be maintained collaboratively.


## Third-Pass UI/UX Improvements

- Removed the Dashboard navigation item. The link pointed to a page that is not part of this frontend and produced a browser file-not-found error, so the primary navigation is now Analyze, How it works, Model, and Tech, all in-page anchors with existing section IDs.
- Reworked the model-information section into a three-state strip that separates backend connectivity, model-artifact availability, and evaluation status. An unreachable API no longer renders as "model artifact unavailable".
- Added a Retry button that re-calls `/api/model-info`, shown only when the API is unreachable.
- Added `DOCUMENTED_*` constants in `frontend/script.js` carrying the verified artifact configuration recorded in `MODEL_CARD.md`, so the architecture, dataset, and evaluation cards stay informative when the backend is offline. These are labelled as documented, not live.
- Improved design-system consistency: heading scale and line lengths, card padding and alignment, pill tone variants (ok/pending/error/unknown), metric-row wrapping, code-block monospace formatting, and error-card presentation.
- Added `prefers-reduced-motion` support for smooth scrolling, transitions, and animations.
- Strengthened keyboard focus indicators with distinct outline colors for dark and light surfaces.
- Connected the four How-it-works steps with visual flow connectors that switch from horizontal to vertical at the tablet breakpoint.
- Added word wrapping for long technical values in metric rows and tech-card metadata.
- Updated tests to remove the `/admin` page-serving assertion, since that page is no longer reachable from the UI.
