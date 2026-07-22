document.addEventListener("DOMContentLoaded", () => {
    const codeInput = document.getElementById("code-input");
    const fileInput = document.getElementById("file-input");
    const dropZone = document.getElementById("drop-zone");
    const fileName = document.getElementById("file-name");
    const analyzeBtn = document.getElementById("analyze-btn");
    const loading = document.getElementById("loading");
    const result = document.getElementById("result");
    const lineCount = document.getElementById("line-count");
    const charCount = document.getElementById("char-count");
    const tabs = document.querySelectorAll(".tab");
    const tabContents = document.querySelectorAll(".tab-content");

    let currentMode = "paste";
    let uploadedCode = "";

    // Tab switching
    tabs.forEach(tab => {
        tab.addEventListener("click", () => {
            tabs.forEach(t => t.classList.remove("active"));
            tabContents.forEach(tc => tc.classList.remove("active"));
            tab.classList.add("active");
            document.getElementById(`tab-${tab.dataset.tab}`).classList.add("active");
            currentMode = tab.dataset.tab;
            result.hidden = true;
            updateAnalyzeButton();
        });
    });

    // Code input stats
    codeInput.addEventListener("input", () => {
        const lines = codeInput.value.split("\n").length;
        const chars = codeInput.value.length;
        lineCount.textContent = `${lines} lines`;
        charCount.textContent = `${chars} chars`;
        result.hidden = true;
        updateAnalyzeButton();
    });

    // File input
    fileInput.addEventListener("change", (e) => {
        const file = e.target.files[0];
        if (!file) return;
        fileName.textContent = file.name;
        const reader = new FileReader();
        reader.onload = (ev) => {
            uploadedCode = ev.target.result;
            updateAnalyzeButton();
        };
        reader.readAsText(file);
    });

    // Drag and drop
    dropZone.addEventListener("click", () => fileInput.click());

    dropZone.addEventListener("dragover", (e) => {
        e.preventDefault();
        dropZone.classList.add("dragover");
    });

    dropZone.addEventListener("dragleave", () => {
        dropZone.classList.remove("dragover");
    });

    dropZone.addEventListener("drop", (e) => {
        e.preventDefault();
        dropZone.classList.remove("dragover");
        const file = e.dataTransfer.files[0];
        if (!file) return;
        fileInput.files = e.dataTransfer.files;
        fileName.textContent = file.name;
        const reader = new FileReader();
        reader.onload = (ev) => {
            uploadedCode = ev.target.result;
            updateAnalyzeButton();
        };
        reader.readAsText(file);
    });

    function updateAnalyzeButton() {
        if (currentMode === "paste") {
            analyzeBtn.disabled = !codeInput.value.trim();
        } else {
            analyzeBtn.disabled = !uploadedCode.trim();
        }
    }

    // Analyze
    analyzeBtn.addEventListener("click", async () => {
        const code = currentMode === "paste" ? codeInput.value : uploadedCode;
        if (!code.trim()) return;

        loading.hidden = false;
        result.hidden = true;
        analyzeBtn.disabled = true;
        analyzeBtn.textContent = "Analyzing...";

        try {
            const langSelect = document.getElementById("lang-select");
            const selectedLang = langSelect ? langSelect.value : "auto";

            const body = { code };
            if (selectedLang !== "auto") {
                body.language = selectedLang;
            }

            const resp = await fetch("/api/analyze", {
                method: "POST",
                headers: { "Content-Type": "application/json" },
                body: JSON.stringify(body),
            });

            if (!resp.ok) {
                const err = await resp.json();
                alert(`Error: ${err.error}`);
                return;
            }

            const data = await resp.json();
            showResult(data);
        } catch (err) {
            alert(`Connection error: ${err.message}`);
        } finally {
            loading.hidden = true;
            analyzeBtn.disabled = false;
            analyzeBtn.innerHTML = `<svg class="btn-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="11" cy="11" r="8"/><path d="M21 21l-4.35-4.35"/></svg> Analyze`;
        }
    });

    function showResult(data) {
        const isAI = data.prediction === "AI Generated";
        const badge = document.getElementById("result-badge");
        badge.className = `result-badge ${isAI ? "ai" : "human"}`;
        document.getElementById("badge-icon").textContent = isAI ? "🤖" : "👤";
        document.getElementById("result-label").textContent = data.prediction;
        document.getElementById("result-language").textContent = data.language;

        const confValue = document.getElementById("confidence-value");
        confValue.textContent = `${data.confidence}%`;

        const confBar = document.getElementById("confidence-bar");
        confBar.className = `confidence-bar ${isAI ? "ai" : "human"}`;
        confBar.style.width = `${data.confidence}%`;

        // Features
        const featuresList = document.getElementById("features-list");
        featuresList.innerHTML = "";

        if (data.features && Object.keys(data.features).length > 0) {
            const entries = Object.entries(data.features);
            const matching = entries.filter(([_, v]) => v.ai_style === isAI);
            const nonMatching = entries.filter(([_, v]) => v.ai_style !== isAI);

            const sorted = [...matching, ...nonMatching];
            sorted.forEach(([key, feat]) => {
                const isMatch = feat.ai_style === isAI;
                const icon = feat.ai_style ? "🤖" : "👤";
                const el = document.createElement("div");
                el.className = "feature-item";
                el.innerHTML = `
                    <span class="feature-icon">${icon}</span>
                    <span class="feature-text">${feat.description}</span>
                    <span class="feature-count">${feat.count}×</span>
                `;
                if (!isMatch) {
                    el.style.opacity = "0.5";
                    el.title = "Counter-indicator (suggests opposite class)";
                }
                featuresList.appendChild(el);
            });
        } else {
            featuresList.innerHTML = `<div class="feature-item" style="color: var(--text2);">No distinctive patterns detected.</div>`;
        }

        result.hidden = false;
        result.scrollIntoView({ behavior: "smooth", block: "start" });
    }

    // Keyboard shortcut: Ctrl+Enter to analyze
    codeInput.addEventListener("keydown", (e) => {
        if (e.ctrlKey && e.key === "Enter") {
            e.preventDefault();
            analyzeBtn.click();
        }
    });
});

