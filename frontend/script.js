const API_BASE_URL = window.CODEALYZE_API_BASE_URL || "";

const MAX_CODE_CHARS = 200000;



// Verified static facts about the checked-in artifact, recorded in MODEL_CARD.md

// and AUDIT_REPORT.md. These describe the artifact configuration and are shown

// even when the backend is offline. They are never presented as live status.

const DOCUMENTED_MODEL_FACTS = {

    model_version: "legacy-codealyze-model",

    feature_extractor: "TfidfVectorizer",

    analyzer: "char_wb",

    ngram_range: "3 to 5 characters",

    max_features: "250,000",

    classifier: "LinearSVC",

    classes: "ai, human",

    supported_languages: "C, C++, Java, Python",

    score_method: "sigmoid_absolute_linear_svm_margin_not_calibrated",

};



const DOCUMENTED_DATASET_STATUS = {

    status: "Dataset not present in this checkout",

    detail:

        "The original training dataset is not committed, so sample counts, duplicate rates, label quality, and leakage cannot be verified. No dataset metrics are displayed.",

};



const DOCUMENTED_EVALUATION_STATUS = {

    status: "Evaluation pending dataset verification",

    detail:

        "No verified holdout evaluation artifact exists in this checkout. Accuracy, precision, recall, F1, and confusion matrices are intentionally omitted rather than estimated.",

};



const DOCUMENTED_LIMITATIONS = [

    "The returned score is an uncalibrated margin-derived display score, not a calibrated probability.",

    "Training-data quality, duplicate rate, and leakage risk are unverified because the dataset is absent.",

    "Very short, obfuscated, or mixed-origin code can be classified unreliably.",

    "The model estimates surface patterns; it does not understand authorship intent.",

    "Code outside the four supported languages falls outside the training distribution.",

];





function escapeHtml(value) {

    return String(value ?? "")

        .replace(/&/g, "&amp;")

        .replace(/</g, "&lt;")

        .replace(/>/g, "&gt;")

        .replace(/"/g, "&quot;")

        .replace(/'/g, "&#39;");

}



function formatCount(value) {

    return typeof value === "number" ? value.toLocaleString("en-US") : "n/a";

}



function formatPercent(value) {

    return typeof value === "number" ? `${(value * 100).toFixed(1)}%` : "n/a";

}



const SAMPLES = {

    python: {

        language: "Python",

        code: `def merge_sort(values):

    if len(values) <= 1:

        return values



    middle = len(values) // 2

    left = merge_sort(values[:middle])

    right = merge_sort(values[middle:])



    result = []

    i = j = 0

    while i < len(left) and j < len(right):

        if left[i] <= right[j]:

            result.append(left[i])

            i += 1

        else:

            result.append(right[j])

            j += 1



    return result + left[i:] + right[j:]`

    },

    java: {

        language: "Java",

        code: `public class PalindromeCheck {

    public static boolean isPalindrome(String text) {

        int left = 0;

        int right = text.length() - 1;



        while (left < right) {

            if (text.charAt(left) != text.charAt(right)) {

                return false;

            }

            left++;

            right--;

        }

        return true;

    }

}`

    },

    cpp: {

        language: "C++",

        code: `#include <iostream>

#include <vector>



int sumValues(const std::vector<int>& values) {

    int total = 0;

    for (int value : values) {

        total += value;

    }

    return total;

}



int main() {

    std::vector<int> values = {1, 2, 3, 4};

    std::cout << sumValues(values) << std::endl;

    return 0;

}`

    },

    c: {

        language: "C",

        code: `#include <stdio.h>



int factorial(int number) {

    int result = 1;

    for (int i = 2; i <= number; i++) {

        result *= i;

    }

    return result;

}



int main(void) {

    printf("%d\\\n", factorial(5));

    return 0;

}`

    }

};



document.addEventListener("DOMContentLoaded", () => {

    const codeInput = document.getElementById("code-input");

    const fileInput = document.getElementById("file-input");

    const dropZone = document.getElementById("drop-zone");

    const fileName = document.getElementById("file-name");

    const analyzeBtn = document.getElementById("analyze-btn");

    const clearBtn = document.getElementById("clear-btn");

    const copyResultBtn = document.getElementById("copy-result-btn");

    const clearResultBtn = document.getElementById("clear-result-btn");

    const loading = document.getElementById("loading");

    const result = document.getElementById("result");

    const emptyState = document.getElementById("empty-state");

    const errorBox = document.getElementById("error");

    const lineCount = document.getElementById("line-count");

    const charCount = document.getElementById("char-count");

    const lineGutter = document.getElementById("line-gutter");

    const apiStatus = document.getElementById("api-status");

    const tabs = document.querySelectorAll(".tab");

    const tabContents = document.querySelectorAll(".tab-content");

    const langSelect = document.getElementById("lang-select");

    const navToggle = document.getElementById("nav-toggle");

    const navLinks = document.getElementById("nav-links");



    let currentMode = "paste";

    let uploadedCode = "";

    let uploadedFileName = "";

    let lastResult = null;



    checkApiStatus();

    loadModelInfo();

    document.getElementById("model-retry-btn")?.addEventListener("click", loadModelInfo);

    updateInputStats();

    updateAnalyzeButton();



    navToggle?.addEventListener("click", () => {

        const isOpen = navLinks.classList.toggle("open");

        navToggle.setAttribute("aria-expanded", String(isOpen));

    });



    navLinks?.querySelectorAll("a").forEach((link) => {

        link.addEventListener("click", () => {

            navLinks.classList.remove("open");

            navToggle?.setAttribute("aria-expanded", "false");

        });

    });



    tabs.forEach((tab) => {

        tab.addEventListener("click", () => {

            tabs.forEach((item) => {

                item.classList.remove("active");

                item.setAttribute("aria-selected", "false");

            });

            tabContents.forEach((content) => content.classList.remove("active"));

            tab.classList.add("active");

            tab.setAttribute("aria-selected", "true");

            document.getElementById(`tab-${tab.dataset.tab}`).classList.add("active");

            currentMode = tab.dataset.tab;

            hideResultState();

            updateAnalyzeButton();

        });

    });



    document.querySelectorAll("[data-sample]").forEach((button) => {

        button.addEventListener("click", () => {

            const sample = SAMPLES[button.dataset.sample];

            codeInput.value = sample.code;

            langSelect.value = sample.language;

            currentMode = "paste";

            document.querySelector('.tab[data-tab="paste"]').click();

            codeInput.focus();

            updateInputStats();

            updateAnalyzeButton();

            hideResultState();

        });

    });



    codeInput.addEventListener("input", () => {

        updateInputStats();

        hideResultState();

        updateAnalyzeButton();

    });



    codeInput.addEventListener("keydown", (event) => {

        if ((event.ctrlKey || event.metaKey) && event.key === "Enter") {

            event.preventDefault();

            if (!analyzeBtn.disabled) analyzeBtn.click();

        }

    });



    clearBtn.addEventListener("click", () => {

        codeInput.value = "";

        uploadedCode = "";

        uploadedFileName = "";

        fileInput.value = "";

        fileName.textContent = "";

        updateInputStats();

        hideResultState();

        updateAnalyzeButton();

        codeInput.focus();

    });



    clearResultBtn?.addEventListener("click", hideResultState);



    copyResultBtn?.addEventListener("click", async () => {

        if (!lastResult) return;

        const score = lastResult.confidence_score ?? lastResult.confidence;

        const text = [

            "CodeAlyze result",

            `Prediction: ${lastResult.prediction || "n/a"}`,

            `Language: ${lastResult.language || "n/a"}`,

            `Model version: ${lastResult.model_version || "unknown"}`,

            `Model score: ${score}% (uncalibrated margin-derived display score)`,

            `Score method: ${lastResult.confidence_method || "not specified"}`,

            `Raw margin: ${lastResult.raw_margin ?? lastResult.raw_score ?? "n/a"}`,

            `Warning: ${lastResult.warning || "Prediction is an estimate, not proof of authorship."}`,

        ].join("\n");



        try {

            await copyText(text);

            setCopyFeedback(copyResultBtn, "Copied", "Copy Result");

        } catch (error) {

            // Do not hide the result on a copy failure; show inline feedback instead.

            setCopyFeedback(copyResultBtn, "Copy failed", "Copy Result");

            console.error("CodeAlyze: clipboard copy failed", error);

        }

    });



    async function copyText(text) {

        if (navigator.clipboard && window.isSecureContext) {

            await navigator.clipboard.writeText(text);

            return;

        }

        // Fallback for plain-http local hosting where the async clipboard API is blocked.

        const helper = document.createElement("textarea");

        helper.value = text;

        helper.setAttribute("readonly", "");

        helper.style.position = "fixed";

        helper.style.opacity = "0";

        document.body.appendChild(helper);

        helper.select();

        const ok = document.execCommand("copy");

        document.body.removeChild(helper);

        if (!ok) throw new Error("Copy command was rejected by the browser.");

    }



    function setCopyFeedback(button, temporaryLabel, defaultLabel) {

        button.textContent = temporaryLabel;

        setTimeout(() => {

            button.textContent = defaultLabel;

        }, 1400);

    }



    fileInput.addEventListener("change", () => {

        const file = fileInput.files[0];

        if (file) readUploadedFile(file);

    });



    dropZone.addEventListener("click", () => fileInput.click());

    dropZone.addEventListener("keydown", (event) => {

        if (event.key === "Enter" || event.key === " ") {

            event.preventDefault();

            fileInput.click();

        }

    });



    dropZone.addEventListener("dragover", (event) => {

        event.preventDefault();

        dropZone.classList.add("dragover");

    });



    dropZone.addEventListener("dragleave", () => {

        dropZone.classList.remove("dragover");

    });



    dropZone.addEventListener("drop", (event) => {

        event.preventDefault();

        dropZone.classList.remove("dragover");

        const file = event.dataTransfer.files[0];

        if (file) readUploadedFile(file);

    });



    analyzeBtn.addEventListener("click", async () => {

        const code = currentMode === "paste" ? codeInput.value : uploadedCode;

        const validationMessage = validateCode(code);

        if (validationMessage) {

            showError(validationMessage);

            return;

        }



        setLoading(true);



        try {

            const body = { code };

            if (currentMode === "paste") {

                if (langSelect.value !== "auto") body.language = langSelect.value;

            } else if (uploadedFileName) {

                body.filename = uploadedFileName;

            }



            const response = await fetch(`${API_BASE_URL}/api/analyze`, {

                method: "POST",

                headers: { "Content-Type": "application/json" },

                body: JSON.stringify(body)

            });



            if (!response.ok) {

                const errorPayload = await response.json().catch(() => ({ error: "Unknown API error" }));

                showError(errorPayload.detail ? `${errorPayload.error}: ${errorPayload.detail}` : errorPayload.error);

                return;

            }



            const data = await response.json();

            showResult(data);

        } catch (error) {

            showError(`Backend unavailable: ${error.message}`);

        } finally {

            setLoading(false);

        }

    });



    async function checkApiStatus() {

        if (!apiStatus) return;

        try {

            const response = await fetch(`${API_BASE_URL}/api/ready`);

            const data = await response.json();

            if (response.ok && data.model?.available) {

                apiStatus.textContent = "Model ready";

                apiStatus.className = "pill ready";

            } else {

                apiStatus.textContent = "Model unavailable";

                apiStatus.className = "pill danger";

            }

        } catch {

            apiStatus.textContent = "API offline";

            apiStatus.className = "pill danger";

        }

    }



    function readUploadedFile(file) {

        uploadedFileName = file.name;

        fileName.textContent = file.name;



        const reader = new FileReader();

        reader.onload = (event) => {

            uploadedCode = String(event.target.result || "");

            updateAnalyzeButton();

            hideResultState();

        };

        reader.onerror = () => showError("Could not read the selected file.");

        reader.readAsText(file);

    }



    function validateCode(code) {

        if (!code || !code.trim()) return "Add source code before running analysis.";

        if (code.length > MAX_CODE_CHARS) return `Code exceeds the ${MAX_CODE_CHARS} character limit.`;

        return "";

    }



    function updateInputStats() {

        const code = codeInput.value;

        const lines = code ? code.split("\n").length : 0;

        lineCount.textContent = `${lines} ${lines === 1 ? "line" : "lines"}`;

        charCount.textContent = `${code.length} / ${MAX_CODE_CHARS} chars`;

        charCount.classList.toggle("danger-text", code.length > MAX_CODE_CHARS);

        lineGutter.textContent = Array.from({ length: Math.max(lines, 1) }, (_, index) => index + 1).join("\n");

    }



    function updateAnalyzeButton() {

        const code = currentMode === "paste" ? codeInput.value : uploadedCode;

        analyzeBtn.disabled = Boolean(validateCode(code));

    }



    function setLoading(isLoading) {

        loading.hidden = !isLoading;

        analyzeBtn.disabled = isLoading || Boolean(validateCode(currentMode === "paste" ? codeInput.value : uploadedCode));

        analyzeBtn.textContent = isLoading ? "Analyzing..." : "Analyze Code";

        if (isLoading) {

            emptyState.hidden = true;

            result.hidden = true;

            errorBox.hidden = true;

        }

    }



    function hideResultState() {

        result.hidden = true;

        errorBox.hidden = true;

        loading.hidden = true;

        emptyState.hidden = false;

    }



    function showError(message) {

        lastResult = null;

        errorBox.textContent = message || "Something went wrong.";

        errorBox.hidden = false;

        result.hidden = true;

        loading.hidden = true;

        emptyState.hidden = true;

    }



    function showResult(data) {

        lastResult = data;

        const isAI = data.prediction === "AI Generated";

        const confidence = data.confidence_score ?? data.confidence ?? 0;



        document.getElementById("result-badge").className = `result-badge ${isAI ? "ai" : "human"}`;

        document.getElementById("badge-icon").textContent = isAI ? "AI" : "HU";

        document.getElementById("result-label").textContent = isAI ? "AI-like code" : "Human-like code";

        document.getElementById("result-language").textContent = data.language || "Unknown language";

        document.getElementById("confidence-value").textContent = `${confidence}%`;

        document.getElementById("confidence-bar").className = `confidence-bar ${isAI ? "ai" : "human"}`;

        document.getElementById("confidence-bar").style.width = `${Math.max(0, Math.min(100, confidence))}%`;

        document.getElementById("model-meta").textContent = `Model: ${data.model_version || "unknown"} | Method: ${data.confidence_method || "not specified"} | Raw margin: ${data.raw_margin ?? data.raw_score ?? "n/a"}`;

        document.getElementById("result-warning").textContent = data.warning || "This prediction is an estimate, not proof of authorship.";

        document.getElementById("result-interpretation").textContent = isAI

            ? "The submitted code is closer to patterns the model associates with AI-generated examples."

            : "The submitted code is closer to patterns the model associates with human-written examples.";



        renderFeatures(data.features || {}, isAI);



        emptyState.hidden = true;

        errorBox.hidden = true;

        loading.hidden = true;

        result.hidden = false;

    }



    function renderFeatures(features, isAI) {

        const featuresList = document.getElementById("features-list");

        featuresList.innerHTML = "";

        const entries = Object.entries(features);



        if (!entries.length) {

            featuresList.innerHTML = '<div class="feature-item muted">No rule-based indicators were detected.</div>';

            return;

        }



        entries

            .sort(([, a], [, b]) => Number(b.ai_style === isAI) - Number(a.ai_style === isAI))

            .forEach(([, feature]) => {

                const item = document.createElement("div");

                item.className = "feature-item";

                item.innerHTML = `

                    <span class="feature-icon">${feature.ai_style ? "AI" : "HU"}</span>

                    <span class="feature-text">${escapeHtml(feature.description)}</span>

                    <span class="feature-count">${feature.count}x</span>

                `;

                featuresList.appendChild(item);

            });

    }



    async function loadModelInfo() {

        renderModelStatusLoading();



        let payload = null;

        try {

            const response = await fetch(`${API_BASE_URL}/api/model-info`);

            if (response.ok) {

                payload = await response.json();

            }

        } catch {

            payload = null;

        }



        // An unreachable API is not evidence that the model is missing.

        // Connectivity, model availability, and evaluation status stay separate.

        if (!payload) {

            renderModelStatusUnreachable();

        } else {

            renderModelStatus(payload);

        }



        renderDatasetStatus(payload);

        renderEvaluationStatus(payload);

        renderLimitations(document.getElementById("model-limitations"), payload && payload.known_limitations);

        renderLiveModelVersion(payload);

    }



    function setStatusPill(elementId, tone, text) {

        const element = document.getElementById(elementId);

        if (!element) return;

        element.innerHTML = `<span class="pill ${tone}">${escapeHtml(text)}</span>`;

    }



    function setStatusDot(elementId, tone) {

        const dot = document.getElementById(elementId);

        if (!dot) return;

        dot.className = `status-key-dot ${tone}`;

    }



    function setRetryVisible(visible) {

        const retry = document.getElementById("model-retry-btn");

        if (retry) retry.hidden = !visible;

    }



    function setStatusTitle(text) {

        const title = document.getElementById("status-strip-title");

        if (title) title.textContent = text;

    }



    function renderModelStatusLoading() {

        setStatusDot("status-dot-backend", "pending");

        setStatusDot("status-dot-model", "pending");

        setStatusDot("status-dot-eval", "pending");

        setStatusPill("status-backend", "pending", "checking");

        setStatusPill("status-model", "pending", "checking");

        setStatusPill("status-eval", "pending", "checking");

        setStatusTitle("Checking backend status");

        setRetryVisible(false);

    }



    function renderModelStatusUnreachable() {

        setStatusDot("status-dot-backend", "error");

        setStatusDot("status-dot-model", "unknown");

        setStatusDot("status-dot-eval", "pending");

        setStatusPill("status-backend", "error", "unreachable");

        setStatusPill("status-model", "unknown", "not reported");

        setStatusPill("status-eval", "pending", "pending");

        setStatusTitle(

            "The API is not reachable right now. The architecture below is the documented artifact configuration, not live runtime state.",

        );

        setRetryVisible(true);

    }



    function renderModelStatus(info) {

        const modelAvailable = Boolean(info.available);

        const evaluation = info.evaluation || {};



        setStatusDot("status-dot-backend", "ok");

        setStatusPill("status-backend", "ok", "reachable");

        setStatusDot("status-dot-model", modelAvailable ? "ok" : "error");

        setStatusPill("status-model", modelAvailable ? "ok" : "error", modelAvailable ? "loaded" : "not loaded");

        setStatusDot("status-dot-eval", evaluation.available ? "ok" : "pending");

        setStatusPill("status-eval", evaluation.available ? "ok" : "pending", evaluation.available ? "available" : "pending");



        setStatusTitle(

            modelAvailable

                ? "Backend reachable and the model artifact loaded successfully."

                : "Backend reachable, but the model artifact could not be loaded. Predictions return an explicit error.",

        );

        setRetryVisible(false);

    }



    function renderLiveModelVersion(payload) {

        const element = document.getElementById("live-model-version");

        if (!element) return;

        const version = (payload && payload.model_version) || DOCUMENTED_MODEL_FACTS.model_version;

        element.textContent = payload ? version : `${version} (documented)`;

    }





    function renderModelInfo(grid, info) {

        const featureConfig = info.feature_config || {};

        const ngramRange = Array.isArray(featureConfig.ngram_range)

            ? `${featureConfig.ngram_range[0]} to ${featureConfig.ngram_range[1]} characters`

            : "n/a";

        const dataset = info.dataset || {};

        const evaluation = info.evaluation || {};



        grid.innerHTML = [

            architectureCard(info, ngramRange, featureConfig),

            datasetCard(dataset),

            evaluationCard(evaluation),

        ].join("");

    }



    function renderDatasetStatus(payload) {

        const dataset = (payload && payload.dataset) || DOCUMENTED_DATASET_STATUS;

        const line = document.getElementById("dataset-status-line");

        const detail = document.getElementById("dataset-status-detail");

        if (!line || !detail) return;



        line.className = `status-line ${dataset.available ? "ok" : "pending"}`;

        line.textContent = dataset.status || DOCUMENTED_DATASET_STATUS.status;

        detail.textContent = dataset.available

            ? `Counts come from ${dataset.dataset_root || "the dataset audit"}.`

            : dataset.detail || DOCUMENTED_DATASET_STATUS.detail;



        const existing = document.getElementById("dataset-metrics");

        if (existing) existing.remove();



        if (dataset.available) {

            const counts = dataset.counts_by_label || {};

            const metrics = document.createElement("div");

            metrics.id = "dataset-metrics";

            metrics.className = "metric-list";

            metrics.innerHTML = metricRows([

                ["Total files", formatCount(dataset.total_files)],

                ["AI-labeled files", formatCount(counts.ai)],

                ["Human-labeled files", formatCount(counts.human)],

                ["Unknown labels", formatCount(dataset.unknown_label_files)],

                ["Empty files", formatCount(dataset.empty_files)],

                ["Short files", formatCount(dataset.short_files)],

                ["Exact duplicate groups", formatCount(dataset.exact_duplicate_group_count)],

                ["Train/test overlap groups", formatCount(dataset.train_test_overlap_group_count)],

            ]);

            detail.insertAdjacentElement("afterend", metrics);

        }

    }



    function renderEvaluationStatus(payload) {

        const evaluation = (payload && payload.evaluation) || DOCUMENTED_EVALUATION_STATUS;

        const card = document.getElementById("evaluation-card");

        if (!card) return;



        const heading = card.querySelector(".status-line");

        if (!heading) return;



        heading.className = `status-line ${evaluation.available ? "ok" : "pending"}`;

        heading.textContent = evaluation.status || DOCUMENTED_EVALUATION_STATUS.status;



        const existing = card.querySelector(".metric-list");

        if (existing) existing.remove();



        if (evaluation.available) {

            const metrics = document.createElement("div");

            metrics.className = "metric-list";

            metrics.innerHTML = metricRows([

                ["Holdout samples", formatCount(evaluation.samples)],

                ["Accuracy", formatPercent(evaluation.accuracy)],

                ["Macro F1", formatPercent(evaluation.macro_f1)],

            ]);

            const note = document.createElement("p");

            note.className = "info-note";

            note.textContent = "Source: reports/evaluation_metrics.json";

            heading.insertAdjacentElement("afterend", metrics);

            metrics.insertAdjacentElement("afterend", note);

        }

    }



    function metricRows(rows) {

        return rows

            .map(

                ([name, value]) =>

                    `<div class="metric-row">

                        <span class="metric-name">${escapeHtml(name)}</span>

                        <span class="metric-value">${value}</span>

                    </div>`,

            )

            .join("");

    }



    function renderLimitations(list, limitations) {

        if (!list) return;

        const items = Array.isArray(limitations) && limitations.length

            ? limitations

            : DOCUMENTED_LIMITATIONS;

        list.innerHTML = items.map((item) => `<li>${escapeHtml(item)}</li>`).join("");

    }

});
