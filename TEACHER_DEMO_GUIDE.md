# CodeAlyze Teacher Demonstration Guide

## 0. Before you start

Run the app once and confirm the analyzer returns a real prediction. Then keep the backend running for the whole demonstration.

```bash
cd backend
python app.py
```

Open `http://127.0.0.1:5000`. Keep a terminal with the Flask log visible so you can show that requests actually reach the model.

If you want a backup plan in case the venue has no internet, note that Google Fonts will not load and the page will fall back to system fonts. Nothing else breaks.

---

## 1. Opening (about 30 seconds)

Read this:

> "CodeAlyze is an academic machine-learning project that estimates whether source code looks AI-generated or human-written. It supports C, C++, Java, and Python. The output is an estimate, not proof of authorship."

Say the last sentence clearly. It is the most important sentence in the presentation.

## 2. Show the landing page (about 1 minute)

Point at, in order:

1. The headline and the disclaimer under the buttons.
2. The preview window, and say: "That sample is illustrative. The real result only appears after I submit code."
3. The technology stack section: Flask, scikit-learn, and dependency-free HTML/CSS/JS.
4. The "How it works" steps.

## 3. Run a live prediction (about 2 minutes)

1. Scroll to **Analyze Code**.
2. Click a labelled sample button, for example "Python sample". Say: "This loads example code; it does not auto-submit anything."
3. Select the matching language.
4. Click **Analyze Code** and let the loading state show.
5. Read the result aloud: predicted class, language, model version.

Then say:

> "The number shown is labelled a model score, not a probability. It comes from the magnitude of the SVM decision margin. The classifier is not calibrated, so I do not present it as a confidence percentage."

## 4. Explain the heuristic indicators (about 45 seconds)

Point at "Detected features" and say:

> "These are static pattern checks, such as snake_case names or inline comments. They are shown for discussion. They are not what the model used to decide, and they are not formal model explanations."

Then point at the model info section and say:

> "The prediction you saw came from the trained pipeline described here, not from these indicators."

## 5. Explain the ML pipeline (about 2 minutes)

Read this:

> "The submitted code is converted into character n-grams, which are short overlapping pieces of text taken with word boundaries respected. TF-IDF gives more weight to distinctive patterns and less weight to patterns that appear almost everywhere. A LinearSVC classifier then decides whether the code is closer to the AI-like or human-like examples in its training data."

Pipeline on screen:

```text
Source code -> validation -> TF-IDF character n-grams -> LinearSVC -> prediction response
```

If asked why character n-grams: "They capture syntax, formatting, punctuation, and naming style across languages without needing a language-specific parser."

## 6. Explain the audit finding (about 1 minute)

Say:

> "The repository contains a real scikit-learn model artifact, but it does not include the original training dataset. Because of that I do not claim a verified accuracy number here."

Point at the status strip and say:

> "These three indicators are separate. The backend is reachable, the artifact is loaded, and evaluation is still pending dataset verification. If the API were offline, only the first would change. The architecture shown below it is the documented artifact configuration, not live runtime state."

Then say:

> "I added dataset audit, training, and evaluation scripts. If the dataset is available, I can run the audit, build a leakage-resistant split, train, and evaluate on a holdout, and this page will display real metrics automatically."

## 7. Closing line

> "The value of this project is the honest pipeline: a real trained model, real inference through a documented API, and evaluation status that reports exactly what is and is not verified."

## 8. Likely questions and honest answers

**What is TF-IDF?** A weighting method that highlights distinctive text patterns and down-weights common ones.

**Why character n-grams instead of parsing the code?** They work across four languages without four parsers, and they capture style signals like formatting and naming.

**Why not call the score a probability?** It is derived from an uncalibrated SVM margin. Calling it a probability would require a calibrated model plus documented calibration quality.

**Can this prove code was AI-written?** No. It estimates surface patterns and must not be used as proof of authorship or misconduct.

**What are the main limitations?** Unverified training data, uncalibrated scores, sensitivity to formatting and boilerplate, and unreliability on very short or mixed-origin code.

**What would improve it?** A verified dataset, leakage-resistant splitting, independent holdout evaluation, calibrated scores, and only then explanation tools such as SHAP or LIME.

## 9. Commands

```bash
cd backend
python app.py
```

Run tests from the project root:

```bash
python -m unittest discover -s tests
```

Audit, train, and evaluate once a dataset exists:

```bash
python scripts/audit_dataset.py --dataset dataset
python scripts/train_model.py --dataset dataset --model logreg
python scripts/evaluate_model.py --dataset path/to/holdout
```

