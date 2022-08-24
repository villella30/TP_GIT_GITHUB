
public:
    /**************** Metodo constructor *****************/
    Motor(int pdir, int ppwm)
    {
        //seteo los pines de direccion y pwm.
        pin_dir = pdir;
        pin_pwm = ppwm;
        //defino los pines de direccion y pwm como salida.
        pinMode(pin_dir, OUTPUT);
        pinMode(pin_pwm, OUTPUT);
        //seteo la velocidad
        speed = default_speed;
    }
    /**************** Metodos o Acciones *****************/
    void setSpeed(int s)
    {
        if (s >= 100)
        {
            //si la veloidad es mayor a 100, seteo la velocidad a 100.
            s = 100;
        }
        else if (s <= 0)
        {
            //si la veloidad es menor a 0, seteo la velocidad a 0.
            s = 0;
        }

        int value = (int)s * 255 / 100;
        speed = value;
    }

    void forward() //Voy hacia adelante.
    {

        //seteo la direccion hacia adelante.
        //NOTA: Utilizo el FLAG invertir, para que el motor se mueva en el sentido contrario.
        //Ya que fisicamente  el motor se encuentra invertido por lo tanto, el motor va hacia atras.
        //De esta forma resolvemos el problema de que el motor se mueva en el sentido contrario.
        digitalWrite(pin_dir, invert);
        //seteo la velocidad.
        analogWrite(pin_pwm, speed);
    }

    void backward() //Voy hacia atras.
    {
        //seteo la direccion hacia atras.
        //NOTA: Utilizo el FLAG invertir, para que el motor se mueva en el sentido contrario.
        //Ya que fisicamente  el motor se encuentra invertido por lo tanto, el motor va hacia adelante.
        //De esta forma resolvemos el problema de que el motor se mueva en el sentido contrario.
        digitalWrite(pin_dir, !invert);
        //seteo la velocidad.
        analogWrite(pin_pwm, speed);
    }

    void invertDirection()
    {
        //cambio el valor del flag invertir.
        invert = !invert;
    }

    void stop() //Freno
    {
        digitalWrite(pin_dir, LOW);
        analogWrite(pin_pwm, 0);
    }
};



void setup(){
}
void loop(){
}
