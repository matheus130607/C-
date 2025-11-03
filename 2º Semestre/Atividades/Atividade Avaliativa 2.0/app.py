# app.py

# Importações
from flask import Flask, render_template, jsonify
import serial
import time


PORTA = 'COM3'    
BAUD_RATE = 9600   
arduino = None     

try:
    # Tenta estabelecer a conexão serial
    arduino = serial.Serial(PORTA, BAUD_RATE, timeout=1)
    time.sleep(2)  # Espera 2 segundos para o Arduino inicializar (necessário)
    
    # Limpa o buffer de entrada para descartar dados de boot ou lixo
    if arduino.is_open:
        arduino.flushInput()
        print(f"Conexão serial estabelecida com sucesso na porta {PORTA}.")
        
except serial.SerialException as e:
    # Se a conexão falhar (porta ocupada, inexistente, etc.)
    print(f"ERRO CRÍTICO: Não foi possível conectar com o Arduino em {PORTA}. Motivo: {e}")
    arduino = None

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


# Rota para obter dados do sensor via AJAX
@app.route('/get_data')
def get_data():
    global arduino # Garante que estamos usando o objeto serial global

    if arduino and arduino.is_open:
        try:
            # 1. Lê os bytes, decodifica para string e remove espaços/novas linhas
            linha = arduino.readline().decode('utf-8').strip()
            
            # 2. Verifica se a linha está vazia (Timeout ou Arduino lento)
            if not linha:
                return jsonify({
                    "temperatura": "N/A", 
                    "error": "Tempo limite de leitura excedido ou buffer vazio."
                })

            # 3. Tenta converter a linha para float
            try:
                temperatura = float(linha)
                # Dados válidos: retorna a temperatura
                return jsonify({"temperatura": temperatura})

            except ValueError:
                # O dado lido (linha) não era um número (ex: "Lendo...", texto, etc.)
                return jsonify({
                    "temperatura": "ERRO", 
                    "error": f"Dado inválido recebido: '{linha}'"
                })

        except Exception as e:
            # Erros de I/O (comunicação serial interrompida)
            print(f"Erro de I/O durante a leitura serial: {e}")
            return jsonify({
                "temperatura": "ERRO CRÍTICO", 
                "error": f"Falha na comunicação: {str(e)}"
            })
    else:
        # Se a conexão inicial falhou ou foi perdida
        return jsonify({
            "temperatura": "OFFLINE", 
            "error": "Arduino não conectado ou a porta está fechada."
        })



if __name__ == '__main__':
    # use_reloader=False é recomendado ao trabalhar com portas serial
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)