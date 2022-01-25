from flask import Flask, request, flash
from flask import redirect, url_for #redirect
from flask import render_template #template
import os, random
from werkzeug.utils import secure_filename

app = Flask(__name__)
UPLOAD_FOLDER = 'C:/Users/sorkg/Documents/face_recog_attendance-main (1)/face_recog_attendance-main/image'
ALLOWED_EXTENSIONS = set(['png', 'jpg', 'jpeg', 'gif'])

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS

@app.route('/', methods=['GET', 'POST'])
def home():
   
    if request.method == 'POST':
        file = request.files['file']
        file.save(secure_filename(file.filename))

    return render_template("index.html")


if __name__ == "__main__":
    HOST = os.environ.get('SERVER_HOST', 'localhost')
    try:
        PORT = int(os.environ.get('SERVER_PORT', '5555'))
    except ValueError:
        PORT = 5555
    app.run(HOST, PORT, debug=True)
