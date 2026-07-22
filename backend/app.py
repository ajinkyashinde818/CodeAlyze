import os
from flask import Flask, send_from_directory
from flask_cors import CORS

from routes import api
from utils import init_db

def create_app():
    app = Flask(__name__, static_folder=None)
    CORS(app)

    app.register_blueprint(api, url_prefix="/api")

    init_db()

    frontend_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), "frontend")

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

    @app.route("/<path:path>")
    def static_files(path):
        return send_from_directory(frontend_dir, path)

    return app


app = create_app()

if __name__ == "__main__":
    app.run(debug=True, port=5000)

