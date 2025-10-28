# Importações
from flask import Flask, render_template, jsonify
import serial
import time

# Configuração da porta serial do Arduino
try:
    arduino = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)  # tempo para estabilizar
except serial.SerialException as e:
    print(f"Erro ao conectar com o Arduino: {e}")
    arduino = None

app = Flask(__name__)

# Rota principal que renderiza a página HTML
@app.route('/')
def index():
    return render_template('index.html')


# Rota para obter dados do sensor
@app.route('/get_data')
def get_data():
    if arduino:
        try:
            linha = arduino.readline().decode('utf-8').strip()
            temperatura = float(linha)
            return jsonify({"temperatura": temperatura})
        except Exception as e:
            return jsonify({"error": str(e)})
    else:
        return jsonify({"error": "Arduino não conectado"})

# Execução do app Flask
if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)
