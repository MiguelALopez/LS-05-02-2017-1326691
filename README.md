<h1>Taller en clase MPI</h1>

* Miguel Angel Lopez - 1326691

Log file:
[Document](https://docs.google.com/document/d/1tH7moLI0xzszNssMyZ-rNcMttFuAVPHQOzPDgREs5ZU)

<h2>Axb.c</h2>

* **distributereceive**

  Esta función esta dividida en tres partes, la primera se encarga de distribuir las tareas a cada uno de los trabajadores, la segunda parte se encarga de recibir la solucion de cada trabajador, y la ultima parte se encarga de enviar un mensaje a cada trabajador informandole que no hay mas tareas por realizar.
 
 * **recive**
   
   Esta funcion se encarga de recibir un vector, y esperar un mensaje para saber cual es su proximo trabajo, este programa esta programado para finalizar una vez recia un mensaje con la etiqueta **TAGPARAR**, de lo contrario seguira trabajando
