all: compilar
compilar: acta app persona criterioEvaluacion main
		g++ -o app acta.o criterioEvaluacion.o persona.o main.o
acta: acta.cpp acta.h
		g++ -c acta.cpp
persona: persona.cpp persona.h
		g++ -c persona.cpp
app: app.cpp app.h
		g++ -c app.cpp
criterioEvaluacion: criterioEvaluacion.cpp criterioEvaluacion.h
		g++ -c criterioEvaluacion.cpp

main: main.cpp app.h acta.h persona.h criterioEvaluacion.h
	  g++ -c main.cpp