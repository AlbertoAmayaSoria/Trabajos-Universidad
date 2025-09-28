import tkinter as tk
from tkinter import messagebox
import random
import unicodedata

# Función para quitar tildes y reemplazar ñ por n
def normalizar_letra(s):
    s = ''.join(c for c in unicodedata.normalize('NFD', s) if unicodedata.category(c) != 'Mn')
    s = s.replace('ñ', 'n').replace('Ñ', 'n')
    return s.lower()

# Grupos de palabras con sus pistas

grupos_palabras = {
    "Animales": [
        ("perro", ["Es un animal doméstico", "Es el mejor amigo del hombre", "Ladra"]),
        ("gato", ["Animal independiente", "Le gusta dormir mucho", "Maúlla"]),
        ("elefante", ["Es enorme", "Tiene trompa", "Vive en la sabana"]),
        ("jirafa", ["Es muy alta", "Tiene manchas", "Se alimenta de hojas altas"]),
        ("delfín", ["Es marino", "Muy inteligente", "Le gusta saltar en el agua"]),
        ("león", ["Es un felino", "Se le conoce como el rey de la selva", "Ruge"]),
        ("oso", ["Hiberna en invierno", "Come miel y peces", "Es muy fuerte"]),
        ("caballo", ["Se usaba para transporte", "Corre rápido", "Relincha"]),
        ("pingüino", ["Vive en zonas frías", "No puede volar", "Nada muy bien"]),
        ("tigre", ["Es un felino", "Tiene rayas", "Habita en Asia"])
    ],
    "Frutas": [
        ("manzana", ["Puede ser roja o verde", "Aparece en cuentos de hadas", "Se come cruda o en pay"]),
        ("pera", ["Tiene forma de gota", "Puede ser verde o amarilla", "Es jugosa"]),
        ("plátano", ["Es alargada", "Amarilla al madurar", "Los monos la adoran"]),
        ("sandía", ["Es grande y verde", "Roja por dentro", "Tiene muchas semillas negras"]),
        ("fresa", ["Es roja", "Tiene semillas por fuera", "Es pequeña y dulce"]),
        ("mango", ["Es tropical", "Tiene una semilla grande", "Es amarillo o naranja"]),
        ("uva", ["Crecen en racimos", "Pueden ser verdes o moradas", "Se usan para hacer vino"]),
        ("cereza", ["Es pequeña", "Es roja", "Se usa como adorno en postres"]),
        ("kiwi", ["Tiene piel marrón peluda", "Es verde por dentro", "Pequeña y deliciosa"]),
        ("piña", ["Tropical", "Amarilla y dulce", "Tiene hojas en la parte superior"])
    ],
    "Países": [
        ("méxico", ["Está en América del Norte", "Tiene mariachis", "Su capital es muy grande"]),
        ("canadá", ["Está en América del Norte", "Muy frío en invierno", "Su bandera tiene una hoja de maple"]),
        ("argentina", ["Está en Sudamérica", "Famosa por el tango", "Su capital es Buenos Aires"]),
        ("chile", ["País muy largo", "Ubicado en Sudamérica", "Su capital es Santiago"]),
        ("españa", ["Está en Europa", "Tiene la Sagrada Familia", "Hablan español"]),
        ("italia", ["Está en Europa", "Forma de bota", "Su capital es Roma"]),
        ("francia", ["Está en Europa", "Su capital es París", "Tiene la Torre Eiffel"]),
        ("japón", ["Está en Asia", "Tiene samuráis y sushi", "Su capital es Tokio"]),
        ("alemania", ["Está en Europa", "Es famosa por la cerveza", "Su capital es Berlín"]),
        ("brasil", ["Está en Sudamérica", "Famoso por el carnaval", "Su capital es Brasilia"])
    ],
    "Colores": [
        ("rojo", ["Es intenso", "Color de la sangre", "Se asocia con el amor"]),
        ("azul", ["Color del cielo", "Color del mar", "Se asocia con la tranquilidad"]),
        ("verde", ["Color de la naturaleza", "El pasto es de este color", "Se asocia con la esperanza"]),
        ("amarillo", ["Es brillante", "El sol se representa así", "También los plátanos"]),
        ("naranja", ["Es cítrico", "Es mezcla de rojo y amarillo", "Es una fruta también"]),
        ("morado", ["Es oscuro", "Se asocia con la realeza", "Es mezcla de azul y rojo"]),
        ("negro", ["Es ausencia de color", "Se asocia con la elegancia", "Es el color de la noche"]),
        ("blanco", ["Es claridad", "Se asocia con la paz", "Es el color de la nieve"]),
        ("rosa", ["Color suave", "Se asocia con la delicadeza", "Muy usado en flores"]),
        ("celeste", ["Color claro", "Parecido al azul", "Color del cielo despejado"])
    ],
    "Profesiones": [
        ("doctor", ["Ayuda a los enfermos", "Trabaja en hospitales", "Usa bata blanca"]),
        ("maestro", ["Enseña en escuelas", "Explica lecciones", "Usa pizarra"]),
        ("ingeniero", ["Diseña estructuras", "Trabaja con planos", "Puede construir puentes"]),
        ("piloto", ["Vuela aviones", "Trabaja en aeropuertos", "Debe saber meteorología"]),
        ("abogado", ["Defiende en juicios", "Conoce leyes", "Trabaja en tribunales"])
    ],
    "Transporte": [
        ("avión", ["Vuela por el aire", "Transporta personas rápido", "Tiene alas y motores"]),
        ("tren", ["Viaja por rieles", "Transporte terrestre", "Larga distancia"]),
        ("barco", ["Se mueve sobre agua", "Puede ser grande o pequeño", "Usa velas o motor"]),
        ("bicicleta", ["Se pedalea", "Es ecológica", "Tiene dos ruedas"]),
        ("automóvil", ["Se conduce en carreteras", "Tiene motor", "Puede ser familiar o deportivo"])
    ]
}

# Variables globales
palabra_secreta = ""
palabra_mostrada = []
pistas = []
errores = 0
letras_usadas = []

# Función para iniciar el juego
def iniciar_juego():
    global palabra_secreta, palabra_mostrada, errores, pistas, letras_usadas
    grupo = grupo_var.get()
    palabra_secreta, pistas = random.choice(grupos_palabras[grupo])
    palabra_mostrada = ["_"] * len(palabra_secreta)
    errores = 0
    letras_usadas = []

    palabra_label.config(text=" ".join(palabra_mostrada))
    pista_label.config(text=f"Pista: {pistas[0]}")
    letras_label.config(text="Letras usadas: ")
    mensaje_label.config(text="¡Adivina la palabra!")

    entrada.config(state="normal")
    boton_adivinar.config(state="normal")
    entrada.delete(0, tk.END)
    dibujar_ahorcado()

# Función para adivinar letra
def adivinar():
    global errores
    letra = entrada.get().lower()
    entrada.delete(0, tk.END)

    if not letra or len(letra) != 1:
        messagebox.showinfo("Atención", "Debes ingresar solo una letra")
        return
    if not letra.isalpha():
        messagebox.showinfo("Atención", "Debes ingresar solo letras")
        return
    if letra in letras_usadas:
        messagebox.showinfo("Atención", f"Ya usaste la letra '{letra}'")
        return

    letras_usadas.append(letra)
    letras_label.config(text="Letras usadas: " + ", ".join(letras_usadas))

    letra_normal = normalizar_letra(letra)
    palabra_normal = normalizar_letra(palabra_secreta)

    if letra_normal in palabra_normal:
        # Revelar letra original con acento o ñ
        for i, l in enumerate(palabra_secreta):
            if normalizar_letra(l) == letra_normal:
                palabra_mostrada[i] = l
        palabra_label.config(text=" ".join(palabra_mostrada))
        if "_" not in palabra_mostrada:
            mensaje_label.config(text="¡Ganaste! La palabra era " + palabra_secreta)
            entrada.config(state="disabled")
            boton_adivinar.config(state="disabled")
    else:
        errores += 1
        mensaje_label.config(text=f"Error {errores}/6")
        if errores == 2:
            pista_label.config(text=f"Pista: {pistas[0]} | {pistas[1]}")
        elif errores == 4:
            pista_label.config(text=f"Pista: {pistas[0]} | {pistas[1]} | {pistas[2]}")
        dibujar_ahorcado()
        if errores >= 6:
            mensaje_label.config(text="Perdiste. La palabra era " + palabra_secreta)
            entrada.config(state="disabled")
            boton_adivinar.config(state="disabled")

# Función para dibujar el ahorcado
def dibujar_ahorcado():
    canvas.delete("all")
    canvas.create_line(50, 250, 150, 250, width=3)  # suelo
    canvas.create_line(100, 250, 100, 50, width=3)  # vertical
    canvas.create_line(100, 50, 200, 50, width=3)   # horizontal
    canvas.create_line(200, 50, 200, 80, width=3)   # cuerda

    if errores >= 1:
        canvas.create_oval(180, 80, 220, 120, width=3)  # cabeza
    if errores >= 2:
        canvas.create_line(200, 120, 200, 180, width=3)  # torso
    if errores >= 3:
        canvas.create_line(200, 130, 170, 160, width=3)  # brazo izquierdo
    if errores >= 4:
        canvas.create_line(200, 130, 230, 160, width=3)  # brazo derecho
    if errores >= 5:
        canvas.create_line(200, 180, 170, 220, width=3)  # pierna izquierda
    if errores >= 6:
        canvas.create_line(200, 180, 230, 220, width=3)  # pierna derecha

# Ventana principal
root = tk.Tk()
root.title("Juego del Ahorcado")
root.geometry("700x700")

tk.Label(root, text="Selecciona un grupo:", font=("Arial", 16, "bold")).pack(pady=10)
grupo_var = tk.StringVar(value="Animales")
grupo_menu = tk.OptionMenu(root, grupo_var, *grupos_palabras.keys())
grupo_menu.config(font=("Arial", 16), width=20, fg="black", bg="lightyellow")
grupo_menu.pack(pady=10)

tk.Button(root, text="Iniciar Juego", command=iniciar_juego, font=("Arial", 16), fg="red").pack(pady=10)

palabra_label = tk.Label(root, text="", font=("Arial", 24), fg="blue")
palabra_label.pack(pady=10)

pista_label = tk.Label(root, text="", font=("Arial", 14), fg="blue", wraplength=600)
pista_label.pack(pady=5)

entrada = tk.Entry(root, font=("Arial", 16))
entrada.pack(pady=5)

boton_adivinar = tk.Button(root, text="Adivinar", command=adivinar, font=("Arial", 16))
boton_adivinar.pack(pady=5)

letras_label = tk.Label(root, text="Letras usadas: ", font=("Arial", 14), fg="purple")
letras_label.pack(pady=5)

mensaje_label = tk.Label(root, text="", font=("Arial", 16), fg="red")
mensaje_label.pack(pady=5)

canvas = tk.Canvas(root, width=300, height=300, bg="white")
canvas.pack(pady=10)

root.mainloop()

