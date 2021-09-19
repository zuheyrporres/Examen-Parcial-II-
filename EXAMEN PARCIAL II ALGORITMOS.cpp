#include<iostream>
using namespace std;


	int opc=0,totEmpleados = 0;
	
	void menu();
	void Cls();
	
	void Agregar_Empleados();
	void consultar_Empleados();
	void consultar_Codigo_de_Empleados();
	int Editar_a_Empleados(int codEmpleado);
	int dato_empleado(int codEmpleado);
	int funcion_calcular_sueldo(float n1, float n2);
	
	
	struct Empleado{
			
		int *cod;	
		string *nombre;
		string *apellido;	
		string *Puesto;
		float *Sueldo_Base;
		float *Bonificacion;
		
	};
	
	Empleado empleado;
	
	int main(){
		
		empleado.cod = new int [totEmpleados];
		empleado.nombre = new string [150];
		empleado.apellido = new string [150];
		empleado.Puesto = new string [150];
		empleado.Sueldo_Base = new float [totEmpleados];
		empleado.Bonificacion = new float [totEmpleados];
				
		menu();
		
		system("PAUSE");
		return 0;
	}
	
	void menu(){
		
		cout<<"<<Bienvenido\n >>"<<endl<<endl;
		cout<<"1. Agregar empleado"<<endl;
		cout<<"2. Editar empleado"<<endl;
		cout<<"3. Buscar a un empleado"<<endl;
		cout<<"4. Consultar todos los empleados"<<endl;
		cout<<"5. Salir"<<endl<<endl;
		cout<<"Ingrese una opcion: ";
		scanf("%i" , &opc); 
		Cls();
		
		switch(opc)
		{
			case 1: Agregar_Empleados() ;break;
	 		case 2: Editar_a_Empleados(0) ;break;
	 		case 3: consultar_Codigo_de_Empleados() ;break;
	 		case 4: consultar_Empleados() ;break;
	 		case 5: Cls(); menu(); break;  
			default:cout<<"Ingrese una opcion valida";  
		}
	 
	system("pause");
	Cls();
	menu();
	
	}
	
	void ingresar_Empleado(){
		
	 	cout<<"Ingrese los datos del empleado"<<endl;
	 	
		cout<<"Codigo del empleado: ";		
		cin>>empleado.cod[totEmpleados];
		
		cin.ignore();	
		cout<<"Nombres del empleado: ";
		getline(cin,empleado.nombre[totEmpleados]);
			
		cout<<"Apellidos del empleado: ";		
		getline(cin,empleado.apellido[totEmpleados]);	
		
		cout<<"Puesto: ";
		getline(cin,empleado.Puesto[totEmpleados]);
			
		cout<<"Sueldo base: ";
		cin>>empleado.Sueldo_Base[totEmpleados];
		
		cout<<"Bonificacion: ";
		cin>>empleado.Bonificacion[totEmpleados];
				
		totEmpleados++;
	
		system("pause");
		Cls();
		menu();	
	
	}
	
	void consultar_Empleados(){
		cout<<"\t Personas Registradas"<<endl<<endl;
		cout<<"Lista de empleados:"<<endl;
		if (totEmpleados==0){		
		cout<<"Por el momento no hay empleados ingresados"<<endl;
		}else{
			for (int i = 0; i < totEmpleados; i++)
			{
			cout<<"------------------------------------------------"<<endl;
			cout<<"Codigo: "<<empleado.cod[i]<<endl;		
			cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
			cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
			cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
			cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
			cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;		
			cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;
			}
		}	
	}
	int dato_empleado(int codEmpleado){
		for (int i = 0; i < totEmpleados; i++)
		{
			if(empleado.cod[i]==codEmpleado){			
				cout<<"Codigo: "<<empleado.cod[i]<<endl;		
				cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
				cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
				cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
				cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
				cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;
				cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;	
			}			
		}	
	}
	void consultarCodigo(){
		int codigoEmpleado;
		cout<<"Datos del empleado: ";
		cin>>codigoEmpleado;
		cout<<"\n "<<endl;	
		dato_empleado(codigoEmpleado);
		cout<<"------------------------------------------------"<<endl;
	}
	
	int EditarEmpleados(int codEmpleado){
		int id_registro, opc=0;
		string nombre, apellidos, puesto;
		float sueldo, bonificacion;
		
		if(codEmpleado==0){
			cout<<"Ingrese el codigo del empleado que desea editar: ";
			cin>>codEmpleado;
		}	
		
		cout<<"------------------------------------------------"<<endl;
			for (int i = 0; i < totEmpleados; i++)
		{
			if(empleado.cod[i]==codEmpleado){			
				cout<<"Codigo: "<<empleado.cod[i]<<endl;		
				cout<<"Nombres: "<<empleado.nombre[i]<<endl;	
				cout<<"Apellidos: "<<empleado.apellido[i]<<endl;					
				cout<<"Puesto: "<<empleado.Puesto[i]<<endl;		
				cout<<"Sueldo base: "<<empleado.Sueldo_Base[i]<<endl;	
				cout<<"Bonificacion: "<<empleado.Bonificacion[i]<<endl;
				cout<<"Sueldo Total: "<<funcion_calcular_sueldo(empleado.Sueldo_Base[i], empleado.Bonificacion[i])<<endl;
				id_registro=i;
			}			
		}
		cout<<"------------------------------------------------"<<endl<<endl;
		
		cout<<"1. Editar Nombres"<<endl;
		cout<<"2. Editar Apellidos"<<endl;
		cout<<"3. Editar Puesto"<<endl;
		cout<<"4. Editar Sueldo"<<endl;
		cout<<"5. Editar Bonificacion"<<endl;
		cout<<"6. Seleccionar otro registro"<<endl<<endl;
		cout<<"7. Salir"<<endl<<endl;
		
		cout<<"ingrese su opcion: ";
		scanf("%i" , &opc); 
		
		switch(opc)
		{
		case 1: 
		 
			cout<<"Nuevos nombres: ";
			cin>>nombre;
			empleado.nombre[id_registro]=nombre;
			Cls();	
			EditarEmpleados(codEmpleado);
			
		;break;
	 	case 2:
	 		
		 	cout<<"Nuevos apellidos: ";
			cin>>apellidos;
			empleado.apellido[id_registro]=apellidos;
			Cls();	
			EditarEmpleados(codEmpleado);
					  
		;break;
	 	case 3:
	 		
		 	cout<<"Nuevo puesto: ";
			cin>>puesto;
			empleado.Puesto[id_registro]=puesto;
			Cls();	
			EditarEmpleados(codEmpleado);
			
		;break;
	 	case 4: 
		 	cout<<"Nuevo Sueldo: ";
			cin>>sueldo;
			empleado.Sueldo_Base[id_registro]=sueldo;
			Cls();	
			EditarEmpleados(codEmpleado);
		;break;
	 	case 5:
		 	cout<<"Nueva bonificacion: ";
			cin>>bonificacion;
			empleado.Bonificacion[id_registro]=bonificacion;
			Cls();	
			EditarEmpleados(codEmpleado);
		;break;
		case 6:
			EditarEmpleados(0);
		;break;
		case 7:
			Cls();
			menu();	
		;break;
		default:cout<<"Opcion no valida";  
		}													
	}
	
	int funcion_calcular_sueldo(float num1, float num2){
		float suma=0;	
		suma = num1+num2;
		return suma;
	}
	
	void Cls(){
		system("cls");
		
	}




