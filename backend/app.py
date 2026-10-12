import os
from flask import Flask, send_from_directory
from flask_cors import CORS

from routes import api
from utils import init_db
from predictor import model_status


DEFAULT_ORIGINS = [
    "http://localhost:5000",
    "http://127.0.0.1:5000",
    "http://localhost:3000",
    "https://code-alyze.vercel.app",
    "https://www.code-alyze.vercel.app",
]


def _allowed_origins():
    configured = os.environ.get("CODEALYZE_ALLOWED_ORIGINS", "").strip()
    if not configured:
        return DEFAULT_ORIGINS
    return [origin.strip() for origin in configured.split(",") if origin.strip()]


def create_app():
    app = Flask(__name__, static_folder=None)
    app.config["MAX_CODE_CHARS"] = int(os.environ.get("CODEALYZE_MAX_CODE_CHARS", "200000"))
    CORS(app, origins=_allowed_origins())

    app.register_blueprint(api, url_prefix="/api")

    init_db()
    app.config["MODEL_STATUS"] = model_status()

    frontend_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), "frontend")
    assets_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), "assets")

    @app.route("/")
    def index():
        return send_from_directory(frontend_dir, "index.html")

    @app.route("/admin")
    @app.route("/admin/")
    @app.route("/admin.html")
    def admin():
        return send_from_directory(frontend_dir, "admin.html")

    @app.route("/index.html")
    def index_html():
        return send_from_directory(frontend_dir, "index.html")

    @app.route("/assets/<path:path>")
    def asset_files(path):
        return send_from_directory(assets_dir, path)

    @app.route("/TEACHER_DEMO_GUIDE.md")
    def teacher_demo_guide():
        return send_from_directory(os.path.dirname(os.path.dirname(__file__)), "TEACHER_DEMO_GUIDE.md")

    @app.route("/<path:path>")
    def static_files(path):
        return send_from_directory(frontend_dir, path)

    return app


app = create_app()

if __name__ == "__main__":
    app.run(debug=os.environ.get("FLASK_DEBUG", "0") == "1", port=int(os.environ.get("PORT", "5000")))

