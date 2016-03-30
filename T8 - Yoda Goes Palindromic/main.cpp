//
//  main.cpp
//  T8 - Yoda Goes Palindromic
//
//  Created by Melissa Trevino on 3/16/16.
//  Copyright © 2016 Melissa Trevino. All rights reserved.
//
//  Melissa Treviño         A00816715
//  María Paula Anastás     A00817285

#include <iostream>
#include <string>
using namespace std;


bool VerPal ( int p[],int i,int &Tam)
{
    int iAux=0, iAuxx=0;
    for(int iA=0; iA<i; iA++)
    {
        iAux+= p[iA];
        iAuxx+= p[iA] % 2;
    }
    
    if(iAuxx > 1)
    {
        cout<<0<<endl;
        return false;
    }
    
    Tam= iAux;
    if(iAuxx==0)
    {
        Tam++;
    }
    
    return true;
}



double Factorial(double facto[],int x)
{
    //la casilla 0 de la lista guarda el factorial más grande que se tiene guardado
    if(facto[0]<x)
    {
        double Aux=facto[int (facto[0])];
        for(int i=int (facto[0]);i<x+1;i++)
        {
            Aux*=i;
            facto[i]=Aux;
        }
        
        facto[0]=x;// nuevo factorial
    }
    
    return facto[x]; //regresa mayor
    
}

void CargaValores( string sFrase, int ArrValores[],int &i) //Busca numero de combinaciones
{
    for(int iC=0; iC<sFrase.length(); iC++)
    {
        sFrase[iC]=toupper(sFrase[iC]); //convierte min a mayusc
    }
    
    int aux=0, conta=0;
    char cTemp;
    
    
    while(sFrase.length()!=0)
    {
        
        cTemp=sFrase[0];
        
        if(ispunct(cTemp) || cTemp==' ')
        {
            sFrase.erase(0,1);
        }else{
            
            sFrase.erase(0,1);
            aux++;
            
            while(sFrase.find(cTemp)!=std::string::npos) // lo encuentra en la frase
            {
                
                if(sFrase[conta]==cTemp)
                {
                    aux++;
                    sFrase.erase(conta,1);
                    conta--;
                    
                }
                conta++;
                
            }
            //Mete los valores al arreglo
            ArrValores[i]=aux;
            // Pasa a casilla de valores siguiente
            i++;
            aux=0;
            conta=0;
        }
        
    }
    
}

void Palindromo(int ArrValores[], int i, double facto[50])
{
    int iTam=0;
    
    
    if(VerPal(ArrValores, i, iTam)) //Verifica  si es palindrome
    {
        double A = Factorial(facto, (iTam-1)/2);
        double B = 1;
        for(int c=0;c<i-1;c++)
        {
            if(ArrValores[c]%2==0)
                B*=Factorial(facto, (ArrValores[c])/2);
            else
            {
                if(ArrValores[c]!=1)
                    B*=Factorial(facto, (ArrValores[c]-1)/2);
            }
        }
        cout<< A/B <<endl;
        
    }
    
}

int main() {
    
    
    int ArrValores[50], iNum=1;
    string sFrase;
    double fact[50]{1,1};
    
    
    while(iNum==1){
        cout<< "Teclea la frase:"<<endl; //Recibe la frase
        getline(cin,sFrase);
        
        int iX=0;
        
        CargaValores(sFrase,ArrValores,iX);
        
        Palindromo(ArrValores, iX, fact);
        iX=0;
        
        cout<< "Otra frase?"<<endl;
        cout<< "1. Si"<<endl;
        cout<< "2. No"<<endl;
        
        cin>> iNum;
        cin.ignore();
        
    };
    
    return 0;
}

/*
 A man, a plan, a canal, Panama!
 arD,R!A
 B.a.C1/
 12[’;. =1
*/