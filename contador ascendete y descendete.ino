//para entradas
int entrada_w = 2;
int entrada_x = 3;
int entrada_y = 4;
int entrada_z = 5;

//para segmentos
int segmento_a = 7;
int segmento_b = 8;
int segmento_c = 9;
int segmento_d = 10;
int segmento_e = 11;
int segmento_f = 12;
int segmento_g = 13;

//para ascendente o descendente
int A_Desc = 26;
//para corriente de displays
int transistor_unidades = 24;
int transistor_decenas = 22;

int transistor_on = 5;
//ascendentes
int unidades;
int decenas;
int v_usar;
//para tiempo
unsigned long timer1;
unsigned long timer2;
//leer el valor ingresado
int v_contador;

void setup() {
  pinMode(segmento_a, OUTPUT);
  pinMode(segmento_b, OUTPUT);
  pinMode(segmento_c, OUTPUT);
  pinMode(segmento_d, OUTPUT);
  pinMode(segmento_e, OUTPUT);
  pinMode(segmento_f, OUTPUT);
  pinMode(segmento_g, OUTPUT);
  pinMode( transistor_unidades, OUTPUT);
  pinMode( transistor_decenas, OUTPUT);
  pinMode(A_Desc, INPUT);
  unidades = 9;
  decenas = 9;
  timer1 = 0;
  timer2 = 0;
  
}

void loop() {
  v_usar=digitalRead(A_Desc) == 0;
  cambiar(v_usar);
  }

void cambiar(int cantidad){
    if(cantidad){
      
      v_contador = valor_sumar(digitalRead(entrada_z), digitalRead(entrada_y),digitalRead(entrada_x), digitalRead(entrada_w));
        if(v_contador == 1 || v_contador == 0){
            v_contador = 1;
            unsegundo();
            contador2digitos();
            displays7segmentos();}
        else{
            unsegundo();
            contador23digitos();
            displays7segmentos();
            }
        }
    else {
      
      v_contador = valor_sumar(digitalRead(entrada_z), digitalRead(entrada_y),digitalRead(entrada_x), digitalRead(entrada_w));
        if(v_contador == 1 || v_contador == 0){
            v_contador = 1;
            unsegundo_descendente();
            contador2digitos_descendente();
            displays7segmentos();}
        else{
            unsegundo_descendente();
            contador23digitos_descendente();
            displays7segmentos();
        }
        }
         
    }
  
int valor_sumar(int z, int y, int x, int w){
  int suma = 0;
  suma = (z * 8) + (y * 4) + (x * 2) + w;
  return suma;
}

void unsegundo() {
  timer2 = (millis() / 1000 );
  if ( timer1 != timer2 ) {
    timer1 = timer2;
    unidades = unidades + v_contador;  // unidades se incrementa cada segundo
  } else { }
}

//ascendente
void contador2digitos() {
  if ( unidades >= 10 ) {
    unidades = 0;
    decenas++;
  } else { }
  if ( decenas == 10 ) {
    decenas = 0;
  } else { }
}

void contador23digitos(){
if ( unidades >= 10 ) {
    unidades = unidades-10;
    decenas++;
  } else { }
  if ( decenas == 10 ) {
    decenas = 0;
  } else { }
  
  
  }
//descendente
void unsegundo_descendente() {
  timer2=(millis()/1000 );
    if ( timer1 != timer2 ) {
      timer1=timer2;
      unidades = unidades - v_contador;    // unidades se decrementa       
    }else{} 
    } 

void contador2digitos_descendente() {
  if ( unidades <= 0 ) {
      unidades = 9;
      decenas--; } 
  if ( decenas < 0 ) {
      decenas = 9;  } 
}

void contador23digitos_descendente() {
  if ( unidades < 0 ) {
      unidades = unidades+10;
      decenas--; } 
  if ( decenas < 0 ) {
      decenas = 9;  } 
}



void displays7segmentos() {
  //primer delay unidades
  digitalWrite(transistor_unidades, HIGH);
  tabladisplay(unidades);
  delay(transistor_on);
  digitalWrite(transistor_unidades, LOW);


  digitalWrite(transistor_decenas, HIGH);
  tabladisplay(decenas);
  delay(transistor_on);
  digitalWrite(transistor_decenas, LOW);
}

void display(int a1, int b1, int c1, int d1, int e1, int f1, int g1)
{
  digitalWrite (segmento_a, a1);
  digitalWrite (segmento_b, b1);
  digitalWrite (segmento_c, c1);
  digitalWrite (segmento_d, d1);
  digitalWrite (segmento_e, e1);
  digitalWrite (segmento_f, f1);
  digitalWrite (segmento_g, g1);
}

void tabladisplay(int variablenumero) {
  switch (variablenumero) {
    case 0:
      display(0, 0, 0, 0, 0, 0, 1);
      break;
    case 1:
      display(1, 0, 0, 1, 1, 1, 1);
      break;

    case 2 :
      display(0, 0, 1, 0, 0, 1, 0);
      break;

    case 3:
      display(0, 0, 0, 0, 1, 1, 0);
      break;

    case 4:
      display(1, 0, 0, 1, 1, 0, 0);
      break;

    case 5:
      display(0, 1, 0, 0, 1, 0, 0);
      break;

    case 6:
      display(0, 1, 0, 0, 0, 0, 0);
      break;

    case 7:
      display(0, 0, 0, 1, 1, 1, 0);
      break;

    case 8:
      display(0, 0, 0, 0, 0, 0, 0);
      break;

    case 9:
      display(0, 0, 0, 1, 1, 0, 0);
      break;
  }
  return;
}
