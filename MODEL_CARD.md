# CodeAlyze Model Card

## Model

Current checked-in artifact: `backend/models/codealyze_model.pkl`

- Format: joblib/pickle scikit-learn artifact
- Model family: character n-gram TF-IDF plus linear classifier
- Verified pipeline: `TfidfVectorizer(analyzer='char_wb', ngram_range=(3, 5), lowercase=False, max_features=250000)` followed by `LinearSVC(max_iter=5000, random_state=42)`
- Classes: `ai`, `human`
- Artifact SHA256: `24A1B3EB36B253C14C65243ABE332A2C3E66F0500C62C83A62F8B20CBE88B814`
- Version label used by the app: `legacy-codealyze-model`

## Intended Use

The model estimates whether C, C++, Java, or Python source code resembles the AI-generated or human-written examples in its training data.

It should not be used as proof of authorship, academic misconduct, employment decisions, or any other high-stakes determination.

## Training Data

The repository does not include the training dataset. The README's claimed 80,000 samples could not be verified from the available files.

Because the original data and split metadata are absent, the following are unknown:

- Collection process
- Label quality
- Duplicate rate
- Source/project overlap
- Train/test leakage
- Per-language class balance
- License compatibility

## Evaluation

No trustworthy evaluation metrics can be claimed for the existing artifact from this repository alone. A previous 100% accuracy claim remains unverified.

`/api/model-info` therefore reports:

- `evaluation.status` = `Evaluation pending dataset verification`
- No `accuracy`, `precision`, `recall`, `F1`, or `confusion_matrix` field

Metrics appear in the API and UI only after a real `reports/evaluation_metrics.json` artifact is produced by `scripts/evaluate_model.py`.

Use:

```bash
python scripts/audit_dataset.py --dataset dataset
python scripts/train_model.py --dataset dataset --model logreg
python scripts/evaluate_model.py --dataset path/to/holdout --model backend/models/codealyze_model.pkl
```

Keep test data separate from model selection and threshold tuning.

## Scores

The current API returns an uncalibrated score derived from `sigmoid(abs(decision_function))`. This is a display score based on SVM margin magnitude, not a calibrated probability.

The response carries `confidence_method` = `sigmoid_absolute_linear_svm_margin_not_calibrated` and an explicit `warning`, so a consumer cannot mistake it for a probability.

If probabilities are required, train and validate a calibrated model, then document calibration quality.


## Limitations

- Unknown training data quality and unknown leakage risk.
- Likely sensitive to formatting, comments, boilerplate, and source-specific artifacts.
- May fail on very short snippets, generated-human hybrids, obfuscated code, code from unsupported languages, or code outside the training distribution.
- Pickle/joblib artifacts should only be loaded from trusted sources.
- Loading with a different scikit-learn version can produce compatibility warnings or invalid behavior.
