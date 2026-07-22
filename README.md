# 🚀 CodeAlyze – AI Code Authenticator

<div align="center">

![Python](https://img.shields.io/badge/Python-3.13-blue?logo=python)
![Flask](https://img.shields.io/badge/Flask-Backend-black?logo=flask)
![Machine Learning](https://img.shields.io/badge/Machine%20Learning-Scikit--Learn-orange)
![Frontend](https://img.shields.io/badge/Frontend-HTML%20%7C%20CSS%20%7C%20JavaScript-blue)
![License](https://img.shields.io/badge/License-MIT-green)

### 🔍 Detect AI-Generated vs Human-Written Source Code Using Machine Learning

🌐 **Live Demo:** https://code-alyze.vercel.app/

</div>

---

# 📖 Overview

CodeAlyze is a Machine Learning based web application that analyzes source code and predicts whether it is:

- 🤖 AI Generated
- 👨‍💻 Human Written

The project supports multiple programming languages and uses a trained machine learning model to classify uploaded or pasted source code.

This project demonstrates:

- Machine Learning
- Feature Engineering
- NLP on Source Code
- Flask REST APIs
- Frontend Development
- Model Deployment
- Production Deployment using Render & Vercel

---

# ✨ Features

## Code Analysis

- Paste source code
- Upload source code files
- AI vs Human prediction
- Confidence score
- Fast inference
- Multi-language support

---

## Supported Languages

- C
- C++
- Java
- Python

---

## Machine Learning

- TF-IDF Character N-Grams
- Linear Support Vector Classifier (LinearSVC)
- Scikit-Learn Pipeline
- Confidence Estimation
- Feature Extraction

---

## Modern Interface

- Responsive UI
- Dark Theme
- Syntax-friendly editor
- Drag & Drop Upload
- Fast Response

---

# 🌐 Live Demo

## Website

https://code-alyze.vercel.app/

---

# 🏗 Architecture

```
                User

                  │

                  ▼

          HTML/CSS/JavaScript

                  │

             Fetch API

                  │

                  ▼

          Flask REST API

                  │

                  ▼

       TF-IDF Vectorizer

                  │

                  ▼

          LinearSVC Model

                  │

                  ▼

      AI / Human Prediction
```

---

# 🧠 Machine Learning Pipeline

```
Source Code

      │

      ▼

Cleaning

      │

      ▼

Feature Extraction
(TF-IDF Character N-Grams)

      │

      ▼

LinearSVC

      │

      ▼

Prediction

      │

      ▼

Confidence Score
```

---

# 📊 Dataset

## Total Dataset

| Category | Files |
|-----------|------:|
| AI Generated | 40,000 |
| Human Written | 40,000 |
| **Total** | **80,000** |

---

## Languages

- C
- C++
- Java
- Python

---

## Dataset Structure

```
dataset/

├── ai/
│   ├── c/
│   ├── cpp/
│   ├── java/
│   └── python/
│
└── human/
    ├── c/
    ├── cpp/
    ├── java/
    └── python/
```

---

# 📈 Model

Algorithm

```
LinearSVC
```

Feature Extraction

```
TF-IDF Character N-Grams
```

Library

```
Scikit-Learn
```

---

# 🛠 Tech Stack

## Frontend

- HTML5
- CSS3
- JavaScript

---

## Backend

- Python
- Flask
- Flask-CORS

---

## Machine Learning

- Scikit-Learn
- NumPy
- Pandas
- Joblib

---

## Deployment

Frontend

- Vercel

Backend

- Render

---

# 📂 Project Structure

```
CodeAlyze/

├── backend/
│   ├── app.py
│   ├── predictor.py
│   ├── routes.py
│   ├── models/
│   └── requirements.txt
│
├── frontend/
│   ├── css/
│   ├── js/
│   ├── images/
│   └── index.html
│
├── dataset/
├── training/
├── README.md
└── LICENSE
```

---

# ⚙ Installation

Clone Repository

```bash
git clone https://github.com/ajinkyashinde818/CodeAlyze.git
```

Go to project

```bash
cd CodeAlyze
```

Install dependencies

```bash
pip install -r requirements.txt
```

Run backend

```bash
python app.py
```

Open browser

```
http://127.0.0.1:5000
```

---

# 🚀 Deployment

Frontend

- Vercel

Backend

- Render

---

# 📷 Screenshots

> Add screenshots inside

```
assets/

homepage.png

prediction.png

upload.png

result.png
```

---

# 📈 Future Improvements

- Deep Learning Models
- CodeBERT Integration
- Explainable AI
- API Authentication
- User Accounts
- History Dashboard
- Batch File Analysis
- More Programming Languages

---

# 🤝 Contributing

Contributions are welcome.

1. Fork the repository

2. Create your branch

```
git checkout -b feature-name
```

3. Commit

```
git commit -m "Added Feature"
```

4. Push

```
git push origin feature-name
```

5. Open Pull Request

---

# 📜 License

This project is licensed under the MIT License.

---

# 👨‍💻 Author

## Ajinkya Babasaheb Shinde

Computer Technology Student

Machine Learning Enthusiast

GitHub

https://github.com/ajinkyashinde818

---

# ⭐ Support

If you like this project, don't forget to ⭐ Star the repository.

It helps support future development.

---

<div align="center">

### ⭐ Thank You for Visiting CodeAlyze ⭐

**Made with ❤️ using Python, Flask and Machine Learning**

</div>