#include <iostream>   
#include <cstring>    
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int x[20], p[20], c[20], l[20], coada[20], bn[20], b[20];

void meniu_prin();
void definitii();
void met_repr();
void parcurgeri();
void conex();
void verif_conex();
void def_conex();
void def_grad();
void grad();
void izolat();
void def_izolat();
void verif_izolat();
void terminal();
void def_terminal();
void verif_terminal();
void lista_adiac();
void vec_muchii();
void matrice_adiac();
void def_matrice();
void verif_matrice();
void latime();
void adancime();
void hamilton();
void def_hamilton();
void verif_hamilton();
void euler();
void def_euler();
void verif_euler();
void aplicatii();
void  pb1();
void  pb2();
void  pb3();
void test();

struct muchie {
    int v1, v2;
} t[4600], r;

void border(string str, int len){
    int i;
    cout<<"\n";
    for(i=0; i<=(len); i+=2)
        cout<<"* ";
    cout<<endl<<str<<endl;
    for(i=0; i<=(len); i+=2)
        cout<<"* ";
    cout<<endl<<endl;
}

void titlu(string t){
    int i;
    string line="";
    cout<<endl<<t<<endl;
    for(i=0; i<t.length()-1; i++)
        line+="-";
    cout<<line<<endl;
}

void ecran_nou(int mode){

    if(mode==1){
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Apăsaţi tasta \"Enter\" pentru a continua: ";
        char x[100];
        cin.getline(x, 100);
    }
    else if(mode==2)
        this_thread::sleep_for(chrono::nanoseconds(100));
    else if(mode==3){
            cout<<endl;
            cout<<"Apăsaţi tasta \"Enter\" pentru a reveni la meniul anterior: ";
            char x[100];
            cin.getline(x, 100);
        }
    else if(mode==4){
            cout<<"Apăsaţi tasta \"Enter\" pentru a continua: ";
            char x[100];
            cin.getline(x, 100);
        }

    if(system("clear")==-1)
        cout<<"A intervenit o eroare- vă rog, resetaţi programul!";
}

void introducere(){
    string s =" Grafuri neorientate ";
    border(s, s.length());    
    cout<<"Niţă Sara, clasa a XII-a B\n\n";
    ecran_nou(1);
    meniu_prin();
}

bool cifra(char c){
    if(c>='0' && c<='9')
        return 1;
    return 0;
}

bool litera(char c){
    if(c>='a' && c<='z')
        return 1;
    return 0;
}

bool is_number(char s[101]) {
    if (strlen(s) == 0) 
    return 0;
    for (int i = 0; s[i]; i++) {
        if (!cifra(s[i]) && s[i] != ' ')
            return 0;
    }
    return 1;
}

bool is_in_interval(char s[101], int a, int b){
    
    if (strlen(s) == 0) 
        return 0;
    
    int x = stoi(string(s));
    return (x>=a && x<=b);
}

int select(int n){
    char opt[101]=""; bool ok;
    do{
        ok=1;
        cout<<endl<<"Introduceţi opţiunea dorită: ";
        cin.getline(opt, 100);
        if(!is_number(opt))
            ok=0; 
        else if(!is_in_interval(opt, 1, n))
            ok=0;
        if(!ok)
            cout<<endl<<"Nu există aceasta opţiune. Încercaţi din nou.";
    }while(!ok);
    
    return stoi(string(opt));
}

void iesire(){
    string s = " Vă mulţumesc pentru atenţie!";
    border(s, s.length()-1);
}

void citire_muchie(int n, int k, int &x, int &y, int a[100][100]){
    char s[101], *p;
    int i;
    bool ok=0;
    
     do{
        ok=1;
        cout<<"muchia "<<k+1<<": ";
        cin.getline(s, 100);
        for(i=0; i<strlen(s); i++){
            if(!(s[i]>='0' && s[i]<='9') && s[i]!=',' && s[i]!=' ')
                ok=0;
        }
        if(!ok)
            cout<<"Nu respectă formatul. Introduceţi din nou!\n";
        else{
            x=0;
            y=0;
            p=strtok(s, " ,");
            while(p!=NULL){
                if(is_number(p)){
                    if(x==0)
                        x=stoi(string(p));
                    else if(y==0)
                        y=stoi(string(p));
                    else
                        ok=0;
                }
                else
                    ok=0;
                p=strtok(NULL, ", ");
            }
        
        
        if(x*y==0) 
            ok=0;
        if(!ok)
            cout<<"O muchie este formată din 2 vârfuri. Introduceţi din nou!\n";
        if(x==y){
                cout<<"Un vârf nu poate avea muchie cu el însusi. Introduceţi din nou!\n";
                ok=0;
        }
        else if(x>n|| y>n){
            cout<<"Cel mai mare vârf este "<<n<<". Introduceţi vârfuri mai mici sau egale cu "<<n<<".\n";
            ok=0;
        }
            else if(a[x][y]==1){
                cout<<"Muchia există deja. Introduceţi alta!\n";
                ok=0;
            }
        }
    }while (!ok);
     
}

void yesno(char s[101]){
    bool ok = 0;
    int i;
    do{
        cin.getline(s, 100);
        ok=1;
        for(i=0; i<strlen(s); i++){
            s[i]=(char)tolower(s[i]);
            if((s[i]>'a' && s[i]<='z' && s[i]!='d' && s[i]!='n' && s[i]!='u') || (cifra(s[i])))
                ok=0;
        }
        if(strlen(s)==0) ok=0;
        
        if(strstr(s, "da")&& strstr(s, "nu"))
            ok=0;
        if(strstr(s, "da")==NULL && strchr(s, 'd'))
            ok=0;
        if(strstr(s, "nu")==NULL && strchr(s, 'n'))
            ok=0;
        if(!ok)
            cout<<"Nu există aceasta opţiune. Încercaţi din nou."<<endl;
        
    }while(!ok);
}

void citire_n_m(int &n, int &m){
    bool ok; char s[101];
        do{
         ok=1;
         cout<<"Numarul vârfurilor pe care vreţi sa le aibă graful (nu poate avea mai mult de 20 de vârfuri): ";
         cin.getline(s, 100);
         if(strlen(s)==0) {
             cout<<"Valoare invalidă. Încercaţi din nou!\n";
             ok=0;
         }
         else{
         if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou!\n";
            ok=0; 
         }
         else{
             n=stoi(string(s));
         
         if (n>20 || n<1)
             {cout<<"Numar invalid. Mai încercaţi o dată.";
              ok=0;}
             
         }
         }
        }while(!ok);
        
           do{
         ok=1;
        cout<<"Numarul muchiilor pe care vreţi sa le aibă graful: ";
         cin.getline(s, 100);
         if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou!\n";
            ok=0; 
         }
         else{
             m=stoi(string(s));
         
         if (m>n*(n-1)/2){
            cout<<"Graful poate avea maxim "<<n*(n-1)/2<<" muchii. Mai încercaţi!"<<endl;
             ok=0;
         }
             
         }
        }while(!ok);
        
}

void citire_graf(int &n, int &m, int a[100][100]){
    for (int i=1; i<=n; i++)
         for (int j=1; j<=n; j++)
             a[i][j]=0;
        int k=0, x, y, i;
        citire_n_m(n, m);
            if(m)
          cout<<"Introduceţi perechile de muchii. Format posibil: \"a b\" sau \"a, b\"  :"<<endl;
          
          for (k=0; k<m; k++){
              citire_muchie(n, k, x, y, a);
              a[x][y]=a[y][x]=1;
              t[k].v1=x;
              t[k].v2=y;
          }
    

}

void definitii(){
    titlu("Graf neorientat");
    cout<<"Se numeşte graf neorientat, o pereche ordonată de mulţimi (X,U), unde:"<<endl;
    cout<<"* X este o mulţime finită şi nevidă (mulţimea vârfurilor sau nodurilor); \n* U este o mulţime de perechi neordonate de elemente din mulţimea X (mulţimea muchiilor).";
    cout<<"\nObservaţii: \n1. Pentru x, y ∈X, (x, y) sau [x, y] reprezintă o muchie; dacă există această muchie, spunem că x şi y sunt vârfuri adiacente în graf."<<endl;
    cout<<"2. Pentru muchia u = (x, y), vârful x este incident cu u, respectiv vârful y este incident cu muchia u."<<endl<<endl;

    titlu("Lanţ");
    cout<<"Se numeşte lanţ în graful neorientat G, o succesiune de vârfuri L = (x1, x2,…, xk), unde x1, x2,…, xkX, cu proprietatea că oricare două vârfuri consecutive sunt adiacente ( adică, există, în graf, muchiile (x1, x2),( x2, x3),…, (xk-1, xk))."<<endl<<endl;

    titlu("Ciclu");
    cout<<"Se numeşte ciclu în graful neorientat G, un lanţ C = (x1, x2,…, xk), unde x1, x2,…, xkX, cu proprietatea că x1 = xk şi muchiile (x1, x2), (x2, x3),…, (xk-1, xk) sunt distincte două câte două."<<endl<<endl;
    ecran_nou(4);
    
    titlu("Graf parţial");
    cout<<"Un graf parţial al unui graf G este un graf G1=(X, V), cu V  U. \nPentru un graf neorientat dat, un graf parţial poate fi graful însuşi sau se poate obţine dîn G păstrând toate vârfurile dar suprimând una sau mai multe muchii."<<endl<<endl;
     
    titlu("Subgraf");
    cout<<"Un subgraf al unui graf G este un graf G’ = (Y, V), cu Y  X şi V  U, unde V va conţine numai muchiile care au ambele extremităţi în noua mulţime Y. \nPentru un graf neorientat dat, un subgraf se poate obţine din G eliminând unul sau mai multe vârfuri şi pastrând doar acele muchii care au ambele extremităţi în mulţimea vârfurilor rămase."<<endl<<endl;

    titlu("Graf complet");
    cout<<"Un graf neorientat în care oricare două vârfuri sunt adiacente, se numeşte graf complet. \n \n";
    ecran_nou(4);
    
    titlu("Graf bipartit");
    cout<<"Un graf G=(X, U) se numeşte graf bipartit dacă există două mulţimi nevide A şi B astfel încât X=A ∪ B, A ∩ B = ∅ şi orice muchie u a lui G are o extremitate în A iar cealaltă în B. Mulţimile A şi B formează o partiţie a lui X." <<endl<<endl;   

    titlu("Graf bipartit complet");
    cout<<"Un graf bipartit G=(X,U) se numeşte bipartit complet dacă pentru oricare două vârfuri x∈A şi y∈B, există în graf muchia [x,y]; adică [x,y]∈U"<<endl<<endl;     
    ecran_nou(3);
    meniu_prin();
 }

void grad(){
    cout<<"\n1. Definiţii"<<endl;
    cout<<"2. Vârf izolat"<<endl;
    cout<<"3. Vârf terminal"<<endl;
    cout<<"4. Revenire "<<endl;
    int opt = select(4);
    ecran_nou(2);
    if (opt==1)
        def_grad();
    if (opt==2)
        izolat();
    if (opt==3)
        terminal();
    if (opt==4)
        meniu_prin();
}
void def_grad(){
    titlu("Gradul unui vârf");
      cout<<"Gradul unui vârf reprezintă numărul muchiilor incidente cu vârful x. (notat cu d(x))"<<endl;
      cout<<"Obs! Într-un graf neorientat G = ( X, U ) cu n vârfuri şi m muchii, suma gradelor tuturor vârfurilor este egală cu dublul numărului de muchii.\n\n";
      ecran_nou(3);
      grad();
     }
     
void izolat(){
    cout<<"\n1. Definiţii"<<endl;
    cout<<"2. Aplicaţie"<<endl;
    cout<<"3. Revenire"<<endl;
    int opt = select(3);
  ecran_nou(2);
  if (opt==1)
     def_izolat();
  if (opt==2)
     verif_izolat();
  if (opt==3)
      grad();
 }
void def_izolat(){
    titlu("Vârf izolat");
    cout<<"Un vârf care nu este adiacent cu niciun alt vârf se numeşte izolat."<<endl;
    cout<<"Obs! Gradul unui vârf izolat este 0."<<endl;
    ecran_nou(3);
    izolat();
 }
void verif_izolat(){
    int n, m, a[100][100];
    titlu("Program vârfuri izolate");
    cout<<"Introduceţi graful pe care vreţi să îl testaţi, iar programul va returna toate vârfurile izolate sau un mesaj în cazul în care nu există astfel de vârfuri.\n";
    citire_graf(n, m, a);
    int d[n+1];
    for (int i=1; i<=n; i++)
     {d[i]=0;
     for (int j=1; j<=n; j++)
        d[i]+=a[i][j];}
    bool ok=0;
    for (int i=1; i<=n; i++)
        if (d[i]==0){
            if(!ok) cout<<"Vârfurile izolate: ";
                cout<<i<<" ";
            ok=1;
        }
    if (!ok)
         cout<<"Nu există vârfuri izolate în graf";
    cout<<endl<<endl;
    
    char s[101];
    cout<<"Vreţi să vedeţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        cout << "void izolat(int n, int m, int a[100][100]) {\n";
        cout << "    int s[n+1];\n";
        cout << "    for (int i = 1; i <= n; i++) {\n";
        cout << "        s[i] = 0;\n";
        cout << "        for (int j = 1; j <= n; j++)\n";
        cout << "            s[i] += a[i][j];\n";
        cout << "    }\n";
        cout << "    int ok = 0;\n";
        cout << "    for (int i = 1; i <= n; i++)\n";
        cout << "        if (s[i] == 0) {\n";
        cout << "            cout << i << \" \";\n";
        cout << "            ok++;\n";
        cout << "        }\n";
        cout << "    if (!ok)\n";
        cout << "        cout << \"Nu există vârfuri izolate în graf\";\n";
        cout << "}\n";
    }
    ecran_nou(3);
    izolat();
 }

void terminal(){
    cout<<"\n1. Definiţii"<<endl;
    cout<<"2. Aplicaţie"<<endl;
    cout<<"3. Revenire"<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        def_terminal();
    if (opt==2)
        verif_terminal();
    if (opt==3)
        grad();
}
void def_terminal(){
    titlu("Vârf terminal");
    cout<<"Un vârf care este adiacent doar cu un alt vârf se numeşte terminal."<<endl;
    cout<<"Obs! Gradul unui vârf terminal este 1. "<<endl;
    ecran_nou(3);
    terminal();
} 
void verif_terminal(){

    int n, m, a[100][100];
    titlu("Program vârfuri terminale");
    cout<<"Introduceţi graful pe care vreţi să îl testaţi, iar programul va returna toate vârfurile terminale sau un mesaj în cazul încare nu există astfel de vârfuri.\n";
    citire_graf(n, m, a);
    int t[n+1];
    for (int i=1; i<=n; i++){
        t[i]=0;
        for (int j=1; j<=n; j++)
            t[i]+=a[i][j];
    }
    bool ok=0;
    for (int i=1; i<=n; i++)
        if (t[i]==1){
            if(!ok) cout<<"Vârfurile terminale: ";
                 cout<<i<<" ";
              ok=1;
        }
    if (!ok)
        cout<<"Nu există vârfuri terminale în graf";

    cout<<endl<<endl;
    char s[101];
    cout<<"Vreţi să vedeţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        cout << "void terminal(int n, int m, int a[100][100]) {\n";
        cout << "    int s[n+1];\n";
        cout << "    for (int i = 1; i <= n; i++) {\n";
        cout << "        s[i] = 0;\n";
        cout << "        for (int j = 1; j <= n; j++)\n";
        cout << "            s[i] += a[i][j];\n";
        cout << "    }\n";
        cout << "    int ok = 0;\n";
        cout << "    for (int i = 1; i <= n; i++)\n";
        cout << "        if (s[i] == 1) {\n";
        cout << "            cout << i << \" \";\n";
        cout << "            ok++;\n";
        cout << "        }\n";
        cout << "    if (!ok)\n";
        cout << "        cout << \"Nu există vârfuri izolate în graf\";\n";
        cout << "}\n";
   }
    ecran_nou(3);
    terminal();     
}

bool e_patratica(int n, int m){
    if (m==n)
        return 1;
    return 0;
}
bool e_binara(int n, int m, int a[100][100]){
    int ok=1;
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
        if (a[i][j]!=0 && a[i][j]!=1)
            ok=0;
    if (ok)
        return 1;
    return 0;
}
bool zero_diag_prin(int n, int m, int a[100][100]){
    int ok=1;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (j==i && a[i][j]!=0)
                ok=0;
    if (ok)
        return 1;
    return 0;
}
bool e_simetrica(int n, int m, int a[100][100]){
     int ok=1;
  for (int i=0; i<n; i++)
     for (int j=0; j<m; j++)
         if (a[i][j]!=a[j][i])
             ok=0;
 if (ok)
     return 1;
 return 0;}
void cond_matrice(int n, int m, int a[100][100]){
    if (e_patratica(n, m) && e_binara(n, m ,a) && zero_diag_prin(n, m, a) && e_simetrica(n, m, a))
        cout<<"Matricea introdusă poate fi matrice de adiacenţă pentru un graf neorientat.\n";
    else 
        cout<<"Matricea introdusă nu poate fi matrice de adiacenţă.\n";
  }

void met_repr(){
    cout<<"\n1. Liste de adiacenţă"<<endl;
    cout<<"2. Vectorul muchiilor"<<endl;
    cout<<"3. Matricea de adiacenţă"<<endl;
    cout<<"4. Revenire "<<endl;
    int opt = select(4);
        ecran_nou(2);
        if (opt==1)
           lista_adiac();
        if (opt==2)
           vec_muchii();
        if (opt==3)
           matrice_adiac();
        if (opt==4)
            meniu_prin();
}      
void lista_adiac(){
    titlu("Program lista de adiacenţă");
    cout<<"Listă de adiacenţă este o colecţie de liste neordonate folosită pentru a reprezenta un anumit graf. Fiecare listă descrie mulţimea vecinilor unui nod dîngraf. \nPentru a exemplifica, introduceţi propriul graf şi programul va furniza lista de adiacenţă. \n"<<endl;
    int n, m, a[100][100];
    citire_graf(n, m, a);
    for (int i=1; i<=n; i++){
        cout<<endl<<i<<": ";
        for (int j=1; j<=n; j++)
            if (a[i][j])
                 cout<<j<<" ";
    }
    cout<<endl<<endl;
     
    char s[101];
    cout<<"Vreţi să vedeţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        cout << "void lista_adiacenta(int n, int m, int a[100][100]) {\n";
        cout << "    for (int i = 1; i <= n; i++) {\n";
        cout << "        cout << endl << i << \": \";\n";
        cout << "        for (int j = 1; j <= n; j++)\n";
        cout << "            if (a[i][j])\n";
        cout << "                cout << j << \" \";\n";
        cout << "    }\n";
        cout << "}\n";
    }
      ecran_nou(3);
      met_repr();
}
void vec_muchii(){
    titlu("Program vectorul muchiilor");
    cout<<"Vectorul muchiilor poate fi reprezentat în memorie sub forma de tablou unidimensional cu elemente de tip struct {int x,y;}:"<<endl;
    cout<<"struct muchie \n   {int x, y;}; \n muchie v[40];"<<endl;
    cout<<"Pentru a exemplifica, introduceţi propriul graf şi programul va furniza vectorul de muchii. \n"<<endl;
     
    int n, m, a[100][100];
    citire_graf(n, m, a);
    bool prima = 1;
    cout<<"U={ ";
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j] && i<=j){
                if(!prima)
                    cout<<", ";
                else
                    prima=0;
                cout<<"("<<i<<","<<j<<")";
            }
    cout<<" }"<<endl;
    ecran_nou(3);
    met_repr();
}

void matrice_adiac(){
    cout<<"\n1. Definiţie + caracteristici"<<endl;
    cout<<"2. Aplicaţie"<<endl;
    cout<<"3. Revenire "<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        def_matrice();
    if (opt==2)
        verif_matrice();
    if (opt==3)
        met_repr();
}
void def_matrice(){
    titlu("Matricea de adiacenţă"); 
    cout<<"Este o matrice cu n linii şi n coloane, ale cărei elemente sunt definite astfel:"<<endl;
    cout<<"a(i,j);"<<endl;
    cout<<"Caracterisiticile matricei de adiacenţă definită pentru un graf neorientat dat sunt:"<<endl;
    cout<<"* este pătratică \n * este binară \n * este simetrică faţă de diagonala principală \n * diagonala principală conţine doar valori egale cu zero. \n";
    ecran_nou(3);
    matrice_adiac();
}
void verif_matrice(){
    titlu("Program matrice de adiacenţă");
    cout<<"Introduceţi o matrice pentru a verifica dacă poate fi matricea de adiacenţă a unui graf neorientat sau nu."<<endl;
    int n, m, a[100][100];
    bool ok; char s[101];
    do{
        ok=1;
        cout<<"Numărul de linii: ";
        cin.getline(s, 100);
        if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou!\n";
            ok=0; 
        }
        else{
            n=stoi(string(s));
            if (n>20 || n<1){
                cout<<"Numar invalid. Mai încercaţi o dată.\n";
                ok=0;
            }
             
        }
    }while(!ok);
    do{
        ok=1;
        cout<<"Numărul de coloane: ";
        cin.getline(s, 100);
        if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou!\n";
            ok=0; 
        }
        else{
            m=stoi(string(s));
            if (m>20 || m<1){
             cout<<"Numar invalid. Mai încercaţi o dată.";
              ok=0;
            }
             
        }
    }while(!ok);

    char matr[1001];
    int i = 0, j = 0;
    cout << "Elementele matricei\n(se vor lua în considerare doar valorile de 0 şi 1 introduse, separate prin spaţii; restul caracterelor vor fi ignorate):\n";
    while (i < n) {
        cin.getline(matr, 1000);
        int len = strlen(matr);
        for (int k = 0; k < len; k++) {
            if (matr[k] == '0' || matr[k] == '1') {
                a[i][j] = matr[k] - '0';
                j++;
                if (j == m) {
                    j = 0;
                    i++;
                }
                if (i == n)  
                    k = len; 
            }
        }
    }
    cout << "Matricea introdusă:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cond_matrice(n, m, a);
    cout<<"\n";
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    yesno(s);
    if(strchr(s, 'd')){
      cout<<"int e_patratica (int n, int m)\n";
      cout<<"   {if (m==n)\n";
      cout<<"       return 1;\n";
      cout<<"   return 0;}\n"<<endl;
      cout<<"int e_binara(int n, int m, int a[100][100])\n";
      cout<<"   {int ok=1;\n";
      cout<<"   for (int i=0; i<n; i++)\n";
      cout<<"       for (int j=0; j<m; j++)\n";
      cout<<"           if (a[i][j]!=0 && a[i][j]!=1)\n";
      cout<<"               ok=0;\n";
      cout<<"   if (ok)\n";
      cout<<"       return 1;\n";
      cout<<"   return 0;}\n"<<endl;
      cout<<"int zero_diag_prin (int n, int m, int a[100][100])\n";
      cout<<"   {int ok=1;\n";
      cout<<"   for (int i=0; i<n; i++)\n";
      cout<<"        for (int j=0; j<m; j++)\n";
      cout<<"            if (j==i && a[i][j]!=0)\n";
      cout<<"               ok=0;\n";
      cout<<"   if (ok)\n";
      cout<<"       return 1;\n";
      cout<<"   return 0;}\n"<<endl;
      cout<<"int e_simetrica(int n, int m, int a[100][100])\n";
      cout<<"   {int ok=1;\n";
      cout<<"   for (int i=0; i<n; i++)\n";
      cout<<"       for (int j=0; j<m; j++)\n";
      cout<<"           if (a[i][j]!=a[j][i])\n";
      cout<<"               ok=0;\n";
      cout<<"   if (ok)\n";
      cout<<"       return 1;\n";
      cout<<"   return 0;}\n"<<endl;
    }
      ecran_nou(3);
      matrice_adiac();
}

void parcurgeri(){
    cout<<"\n1. În lăţime"<<endl;
    cout<<"2. În adâncime"<<endl;
    cout<<"3. Revenire "<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        latime();
    if (opt==2)
        adancime();
    if (opt==3)
        meniu_prin();
    }

void bfs(int n, int a[100][100], int start){
    int i,k,st,dr;
    st=dr=1;
    coada[1]=start;
    bn[start]=1;
    while(st<=dr){
        k=coada[st];
        for(i=1;i<=n;i++)
            if(bn[i]==0 && a[k][i]==1){
                bn[i]=1;
                coada[++dr]=i;
            }
          st++;
    }
    cout<<"Numărul de vârfuri vizitate: "<< dr; 
}
void latime(){
    titlu("Program parcurgere în lăţime");
    cout << "Parcurgerea în lățime (BFS) urmează pașii:\n";
    cout << "* Se vizitează vârful de start, apoi toți vecinii săi nevizitați.\n";
    cout << "* Apoi se vizitează vecinii nevizitați ai acestora, și tot așa, pe niveluri.\n";
    cout << "* Se folosește o coadă pentru a păstra ordinea de vizitare.\n";
    cout << "* Un vector caracteristic marchează vârfurile deja vizitate.\n\n";
    cout<<"Introduceţi un graf pentru a exemplifica algoritmul de parcurgere în laţime. Programul va returna numarul de vârfuri vizitate.\n";
    int n, m, a[100][100];
    citire_graf(n, m, a);
    bfs(n, a, 1);
    cout<<endl<<endl;
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    char s[101];
    yesno(s);
    if(strchr(s, 'd')){
        cout<<"int i,k,st,dr;"<<endl;
        cout<<"st=dr=1;"<<endl;
        cout<<"x[1]=start;"<<endl;
        cout<<"v[start]=1;"<<endl;
        cout<<"while(st<=dr)"<<endl;
        cout<<"   {k=x[st];"<<endl;
        cout<<"   for(i=1;i<=n;i++)"<<endl;
        cout<<"   if(v[i]==0 && a[k][i]==1)"<<endl;
        cout<<"       {v[i]=1;"<<endl;
        cout<<"       x[++dr]=i;}"<<endl;
        cout<<"   st++;}"<<endl;
        cout<<"cout<<dr;"<<endl<<endl;
    }
      ecran_nou(3);
      parcurgeri();
}

int dfs(int k, int a[100][100], int n){
    b[k] = 1;
    int cnt = 1; 
    for(int i = 1; i <= n; i++) 
        if(a[k][i] == 1 && b[i] == 0)
            cnt += dfs(i, a, n); 
    return cnt;
}
void adancime(){
    titlu("Program parcurgere în adâncime");
    cout << "Parcurgerea în adâncime (DFS) urmează pașii:\n";
    cout << "* Se pornește dintr-un vârf inițial x (vârf curent).\n";
    cout << "* Se vizitează x, apoi se trece la primul său vecin nevizitat, care devine noul vârf curent.\n";
    cout << "* Procesul continuă în adâncime până la un vârf fără vecini nevizitați.\n";
    cout << "* Atunci se revine la părintele său și se continuă cu următorii vecini nevizitați.\n";
    cout << "* Se repetă până când toate vârfurile accesibile din x au fost vizitate.\n\n";
    cout << "\nIntroduceți un graf pentru a exemplifica parcurgerea. Programul va afișa numărul de vârfuri vizitate.\n";
    int n, m, a[100][100];
    citire_graf(n, m, a);
    cout<<"Numărul de vârfuri vizitate: "<<  dfs(1, a, n);
    cout<<endl<<endl;
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    char s[101];
    yesno(s);
    if (strchr(s, 'd')) {
        cout << "int dfs(int k, int a[100][100], int n) {\n";
        cout << "    b[k] = 1;\n";
        cout << "    for(int i = 1; i <= n; i++)\n";
        cout << "        if(a[k][i] == 1 && b[i] == 0)\n";
        cout << "            dfs(i, a, n);\n";
        cout << "}\n";
    }
    ecran_nou(3);
    parcurgeri();
}

void conex(){
    cout<<"\n1. Definiţie graf conex, componenta conexă"<<endl;
    cout<<"2. Verificare graf conex"<<endl;
    cout<<"3. Revenire"<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        def_conex();
    if (opt==2)
        verif_conex();
    if (opt==3)
        meniu_prin();
}
void def_conex(){
    titlu("Graf conex");
    cout<<"Un graf neorientat este conex dacă oricare două vârfuri ale sale pot fi extremităţile unui lanţ."<<endl;
    titlu("Componenta conexă");
    cout<<"Se numeşte componentă conexă a unui graf neorientat G = (X,U), un subgraf G 1 = (Y, V) al lui G, conex, cu proprietatea că nu există niciun lanţ care să aibă o extremitate în Y şi cealaltă în X-Y."<<endl;
    cout<<"Obs! Un graf conex are o singură componentă conexă."<<endl;
    ecran_nou(3);
    conex();
}

bool nu_exista_nod_nevizitat(int l[20], int n){
    for(int i=1;i<=n;i++)
    if(l[i]==0)
        return 0; 
    return 1;  
}
void parcurgere_latime(int a[100][100], int n,int ns){ 
    for(int i=0; i<=n; i++)
        l[i]=0;
    l[ns]=1;
    int prim=1, ultim=1;
    c[ultim]=ns;
    while(prim<=ultim){
        for(int i=1;i<=n;i++)
            if(a[c[prim]][i]==1)
        if(l[i]==0){
            ultim++;
            c[ultim]=i;
            l[i]=1;
        }
        prim++;
    }
}
bool cond_conex(int a[100][100], int n){
    parcurgere_latime(a, n, 1);
    return nu_exista_nod_nevizitat(l, n);
}
void verif_conex(){
    titlu("Program conexitate");
    cout<<"Introduceţi un graf pentru a verifica dacă este conex sau nu."<<endl;
    int n, m, a[100][100];
    citire_graf(n, m, a);
    if (cond_conex(a, n))
        cout<<"Graful este conex.";
    else
        cout<<"Graful nu este conex.";
    cout<<endl<<endl;
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    char s[101];
    yesno(s);
    if(strchr(s, 'd')){
         cout<<"Programul este alcatuit din 2 functii, prima face parcurgerea în latime a grafului iar a doua verifica dacă există vreun nod nevizitat."<<endl;
          cout<<"void parcurgere_latime(int a[20][20], int n, int ns) //ns reprezinta nodul start\n";
          cout<<"   { \n";
          cout<<"     v[ns]=1;\n";
          cout<<"     cout<<ns<<" ";\n";
          cout<<"     int prim=1, ultim=1;\n";
          cout<<"     c[ultim]=ns;\n";
          cout<<"     while(prim<=ultim)\n";
          cout<<"       {for(int i=1;i<=n;i++)\n";
          cout<<"           if(a[c[prim]][i]==1)\n";
          cout<<"               if(v[i]==0)\n";
          cout<<"                   { ultim++\n";
          cout<<"                   c[ultim]=i;\n";
          cout<<"                   cout<<i<<" ";\n";
          cout<<"                   v[i]=1;}\n";
          cout<<"               prim++;}\n";
          cout<<"        cout<<endl;}\n"<<endl;
          cout<<"Dacă există vreun nod nevizitat, graful nu este conex. In functia main avem:";
          cout<<"  citire_graf(n, m, a);\n";
          cout<<"  parcurgere_latime(a, n, 1);\n";
          cout<<"  if (exista_nod_nevizitat(v,n)!=0)\n";
          cout<<"       cout<<'Graful NU este conex!';\n";
          cout<<"  else\n";
          cout<<"       cout<<'Graful este conex!';\n"<<endl;
    }
    ecran_nou(3);
    conex();
}

void hamilton(){
    cout<<"\n1. Teorie"<<endl;
    cout<<"2. Verificare"<<endl;
    cout<<"3. Revenire "<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        def_hamilton();
    if (opt==2)
        verif_hamilton();
    if (opt==3)
        meniu_prin();
}
void def_hamilton(){
    titlu("Ciclu hamiltonian");
    cout<<"Se numeşte ciclu hamiltonian într-un graf neorientat G, un ciclu elementar care conţine toate vârfurile grafului."<<endl;
    titlu("Graf hamiltonian");
    cout<<"Se numeşte graf hamiltonian, un graf care conţine un ciclu hamiltonian."<<endl;
    cout<<"Teorema! \nDacă într-un graf G = (X, U) cu n≥ 3 vârfuri, gradul fiecărui vârf x verifică condiţia d(x) ≥ n / 2, graful este hamiltonian."<<endl;
    ecran_nou(3);
    hamilton();
}
void cond_hamilton_back(int k, bool &ok, int a[100][100], int n){
    for(int i = 1 ; i <= n && !ok; i++)
        if(!p[i]){
            p[i] = 1;
            x[k] = i;
            if(k == 1 || a[x[k - 1]][x[k]] == 1){
                if(k == n && a[x[k]][x[1]] == 1) ok=1;
                else cond_hamilton_back(k + 1, ok, a, n);
            }
            p[i] = 0;
        }
}
void verif_hamilton(){
    titlu("Program graf hamiltonian");
    cout<<"Introduceţi un graf pentru a verifica dacă este hamiltonian sau nu."<<endl;
    int n, m, a[100][100]; bool ok=0;
    for(int i=1; i<21; i++){
        p[i]=0;
        x[i]=0;
    }
    citire_graf(n, m, a);
    cond_hamilton_back(1, ok, a, n);
    cout<<endl;
    if (ok)
       cout<<"Graful introdus este hamiltonian.";
    else 
       cout<<"Graful introdus nu este hamiltonian.";
    cout<<endl<<endl;
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    char s[101];
    yesno(s);
    if(strchr(s, 'd')){
        cout << "int n , a[22][22] , x1 , y , x[20] , ok , p[20];" << endl;
        cout << "void afisare()" << endl;
        cout << "{" << endl;
        cout << "     if (ok)" << endl;
        cout << "        cout<<\"Graful introdus este hamiltonian.\";" << endl;
        cout << "     else" << endl;
        cout << "        cout<<\"Graful introdus nu este hamiltonian.\";" << endl;
        cout << "}" << endl;
        
        cout << "void back(int k)" << endl;
        cout << "{" << endl;
        cout << "    for(int i = 1 ; i <= n && !ok; i++)" << endl;
        cout << "        if(!p[i])" << endl;
        cout << "        {" << endl;
        cout << "            p[i] = 1;" << endl;
        cout << "            x[k] = i;" << endl;
        cout << "            if(k == 1 || a[x[k - 1]][x[k]] == 1)" << endl;
        cout << "            {" << endl;
        cout << "                if(k == n && a[x[k]][x[1]] == 1) afisare();" << endl;
        cout << "                else back(k + 1);" << endl;
        cout << "            }" << endl;
        cout << "            p[i] = 0;" << endl;
        cout << "        }" << endl;
        cout << "}" << endl;
        cout << "//Obs! apelul functiei: back(1); apoi trebuie apelata afisare()" << endl;
    }
    ecran_nou(3);
    hamilton();
}
     
void euler(){
    cout<<"\n1. Teorie"<<endl;
    cout<<"2. Verificare"<<endl;
    cout<<"3. Revenire "<<endl;
    int opt = select(3);
    ecran_nou(2);
    if (opt==1)
        def_euler();
    if (opt==2)
        verif_euler();
    if (opt==3)
        meniu_prin();
     }
void def_euler(){
    titlu("Ciclu eulerian");
    cout<<"Se numeşte ciclu eulerian într-un graf neorientat G, un ciclu care conţine toate muchiile grafului."<<endl;
    titlu("Graf eulerian");
    cout<<"Se numeşte graf eulerian, un graf care conţine un ciclu eulerian."<<endl;
    cout<<"Teorema! \nUn graf neorientat G fără vârfuri izolate este eulerian, dacă şi numai dacă este conex şi gradele tuturor vârfurilor sunt numere pare."<<endl;
    ecran_nou(3);
    euler();
}
bool gr_pare(int n,int a[100][100]){
    int s[n+1];
    bool ok=1;
    for (int i=1; i<=n; i++)
        s[i]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            s[i]+=a[i][j];
        if (s[i]%2==1)
            ok=0;
    }
    return ok;
}
bool nu_ex_gr_zero(int n, int a[100][100]){
    int s[n+1];
    bool ok=1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            s[i]+=a[i][j];
        if(!s[i])
            ok=0;
    }
    return ok;
}
void verif_euler(){
    titlu("Program graf eulerian");
    cout<<"Introduceţi un graf pentru a verifica dacă este eulerian sau nu."<<endl;
    int n, m, a[100][100];
    citire_graf(n, m, a);
    cout<<endl;
    if (cond_conex(a, n) && nu_ex_gr_zero(n, a) && gr_pare(n, a))
        cout<<"Graful introdus este eulerian.";
    else 
        cout<<"Graful introdus nu este eulerian.";
    cout<<endl<<endl;
    cout<<"Vreţi să vedeţi programul? Da/Nu: "; 
    char s[101];
    yesno(s);
    if(strchr(s, 'd')){
        cout<<"Pentru a fi eulerian, graful trebuie sa fie conex. Ca sa vedeţi algoritmul pentru graf conex, duceţi-vă la meniul \"Verificare graf conex\"."<<endl;
        cout<<"int gr_pare(int n,int a[100][100])\n";
        cout<<"   {int ok=1, s[n+1];\n";
        cout<<"    for (int i=1; i<=n; i++)\n";
        cout<<"       {for (int j=1; j<=n; j++)\n";
        cout<<"           s[i]+=a[i][j];\n";
        cout<<"       if (s[i]%2==1)\n";
        cout<<"           ok=0;}\n";
        cout<<"   return ok;}  //cu ajutorul acestei functii, am verificat dacă toate gradurile din graf sunt pare\n"<<endl;
        cout<<"int nu_ex_gr_zero(int n, int a[100][100])\n";
        cout<<"   {int ok=1, s[n+1];\n";
        cout<<"   for (int i=1; i<=n; i++)\n";
        cout<<"       {for (int j=1; j<=n; j++)\n";
        cout<<"           s[i]+=a[i][j];\n";
        cout<<"       if (!s[i])\n";
        cout<<"           ok=0;}\n";
        cout<<"   return ok;}  //această funcţie verifică dacă nu există vârfuri izolate\n"<<endl;
    }
    ecran_nou(3);
    euler();
}

void aplicatii(){cout<<"\n1. Aplicaţie #1"<<endl;
    cout<<"2. Aplicaţie #2"<<endl;
    cout<<"3. Aplicaţie #3"<<endl;
    cout<<"4. Revenire"<<endl;
    int opt = select(4);
    ecran_nou(2);
    if (opt==1)
        pb1();
    if (opt==2)
        pb2();
    if (opt==3)
        pb3();
    if (opt==4)
        meniu_prin();
}

void  pb1(){
    cout<<"1. Se dă lista muchiilor unui graf neorientat. Să se afişeze matricea de adiacenţă a grafului."<<endl<<endl;
    cout<<"Algoritm de rezolvare:"<<endl;
    cout<<" void pb1(){"<<endl;
    cout<<"   int n , m , a[101][101] , x , y;"<<endl;
    cout<<"   int i, j;"<<endl;
    cout<<"   cin>>n>>m;"<<endl;
    cout<<"   for(i=1; i<=n; i++)"<<endl;
    cout<<"     for(j=1; j<=n; j++)"<<endl;
    cout<<"       a[i][j]=0;"<<endl;
    cout<<"   for(i=1; i<=m; i++){"<<endl;
    cout<<"     cin>>x>>y;"<<endl;
    cout<<"     a[x][y] = 1;"<<endl;
    cout<<"     a[y][x] = 1;"<<endl;
    cout<<"   }"<<endl;
    cout<<"   for(i = 1 ; i <= n ; ++i){"<<endl;
    cout<<"     for(j = 1 ; j <= n ; ++j)"<<endl;
    cout<<"       cout << a[i][j] << " ";"<<endl;
    cout<<"     cout << endl;"<<endl;
    cout<<"   }"<<endl;
    cout<<" }"<<endl<<endl;

    int n, m, a[100][100]; char s[101];
    cout<<"Vreţi să încercaţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        citire_graf(n, m, a);
        cout<<endl;
        cout<<"Matricea de adiacenţă: \n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }
    ecran_nou(3);
    aplicatii();
}
    
void  pb2(){
    cout<<"2. Se dă lista muchiilor unui graf neorientat şi un nod k. Să se determine nodurile din graf care au gradul egal cu gradul nodului k."<<endl<<endl;
    cout<<"Algoritm de rezolvare:"<<endl;
    cout<<" void pb2(){"<<endl;
    cout<<"   int i , j, x, y;"<<endl;
    cout<<"   int n , a[105][105], g[105], k;"<<endl;
    cout<<"   for(i=1; i<=n; i++)"<<endl;
    cout<<"     for(j=1; j<=n; j++)"<<endl;
    cout<<"       a[i][j]=0;"<<endl;
    cout<<"   for(i=1; i<=n; i++)"<<endl;
    cout<<"     g[i]=0;"<<endl;
    cout<<"   cin >> n >> m>> k;"<<endl;
    cout<<"   for(i=1; i<=m; i++){"<<endl;
    cout<<"     cin>>x>>y;"<<endl;
    cout<<"     a[x][y] = a[y][x] = 1;"<<endl;
    cout<<"   }"<<endl;
    cout<<"   for(i = 1; i <= n; i++){"<<endl;
    cout<<"     g[i] = 0;"<<endl;
    cout<<"     for(int j = 1; j <= n; ++j)"<<endl;
    cout<<"     if(a[i][j] == 1)"<<endl;
    cout<<"       g[i] ++;"<<endl;
    cout<<"   }"<<endl;
    cout<<"   for(i = 1; i <= n; i++)"<<endl;
    cout<<"     if(g[i] == g[k] && i!=k)"<<endl;
    cout<<"       cout << i << ' ';"<<endl;
    cout<<"   cout << endl;"<<endl;
    cout<<" }"<<endl;
    cout<<endl;
    
    int n, m, a[100][100], i; char s[101];
    cout<<"Vreţi să încercaţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        citire_graf(n, m, a);
        int g[105], k;
        bool ok;

        do{
            ok=1;
            cout<<"vârful k = ";
            cin.getline(s, 100);
            if(!is_number(s)){
                cout<<"Valoare invalidă. Încercaţi din nou!\n";
                ok=0; 
            }
            else{
                k=stoi(string(s));
                if(!k || k>n){
                    cout<<"Numerotarea nodurilor începe de la 1 şi se termină în "<<n<<". Nu există nodul "<<k <<"."<<endl;
                    ok=0;
                }
            }
        }while(!ok);
        
        
        for(i=1; i<=n; i++)
            g[i]=0;
        for(i = 1; i <= n; i++){
            g[i] = 0;
            for(int j = 1; j <= n; ++j)
                if(a[i][j] == 1)
                    g[i] ++;
        }
        cout<<"\nVârfurile cu acelaşi grad ca vârful k: ";
        for(i = 1; i <= n; i++)
            if(g[i] == g[k] && i!=k)
                cout << i << ' ';
        
        cin.get();
        cout << endl;
    }
    ecran_nou(3);
    aplicatii();
}

void  pb3(){
    cout<<"3. Se dă lista muchiilor unui graf neorientat cu n vârfuri, etichetate de la 1 la n. Să se determine câte varfuri au gradul maxim şi să se afişeze aceste vârfuri."<<endl<<endl;
    cout<<"Algoritm de rezolvare:"<<endl;
    cout<<" void pb3(){"<<endl;
    cout<<"   int n , m , a[101][101] , p , r , e[2500], i, j;"<<endl;
    cout<<"   int cmax = -1 , x = 0, cnt;"<<endl;
    cout<<"   cin >> n>>m;"<<endl;
    cout<<"   for(i=1; i<=n; i++)"<<endl;
    cout<<"     for(j=1; j<=n; j++)"<<endl;
    cout<<"       a[i][j]=0;"<<endl;
    cout<<"   for(i=1; i<=m; i++){"<<endl;
    cout<<"     a[p][r] = 1;"<<endl;
    cout<<"     a[r][p] = 1;"<<endl;
    cout<<"   }"<<endl;
    cout<<"   for(int i = 1 ; i <= n ; ++i){"<<endl;
    cout<<"      cnt = 0;"<<endl;
    cout<<"      for(int j = 1 ; j <= n ; ++j)"<<endl;
    cout<<"        if(a[i][j]) cnt++;"<<endl;
    cout<<"   if(cnt > cmax)"<<endl;
    cout<<"      cmax = cnt;"<<endl;
    cout<<"      x = 1;"<<endl;
    cout<<"   }"<<endl;
    cout<<"  else if(cnt == cmax) x++;"<<endl;
    cout<<"  cout << x <<endl;"<<endl;
    cout<<"  for(int i = 1 ; i <= n ; ++i){"<<endl;
    cout<<"     int cnt = 0;"<<endl;
    cout<<"     for(int j = 1 ; j <= n ; ++j)"<<endl;
    cout<<"       if(a[i][j]) cnt++;"<<endl;
    cout<<"       if(cnt == cmax) cout << i << " ";"<<endl<<endl;
    cout<<"   }"<<endl;
    cout<<" }"<<endl;
    int n, m, a[100][100]; char s[101];

    cout<<"Vreţi să încercaţi programul? Da/Nu: ";
    yesno(s);
    if(strchr(s, 'd')){
        citire_graf(n, m, a);
        int  i, j;
        int cmax = -1 , x = 0;
        for(i=  1 ; i <= n ; ++i){
            int cnt = 0;
            for( j = 1 ; j <= n ; ++j)
               if(a[i][j]) cnt++;
                
            if(cnt > cmax) {
                cmax = cnt;
                x = 1;
            }
                
            else if(cnt == cmax) x++;
                
        }
        cout<<"\nNumărul de vârfuri cu gradul maxim: "<<x<<endl;
        cout<<"Vârfurile cu gradul maxim: ";
        for(i = 1 ; i <= n ; ++i){
            int cnt = 0;
            for(j = 1 ; j <= n ; ++j)
                if(a[i][j]) cnt++;
            if(cnt == cmax) cout << i << " ";
        }
        
        cout<<endl;
    }
    ecran_nou(3);
    aplicatii();
}

int citire_numar (){
    bool ok; char s[101];
    do{
        ok=1;
        cout<<"Răspuns: ";
        cin.getline(s, 100);
        if(!is_number(s)){
            cout<<"Valoare invalidă. Încercaţi din nou.\n";
        ok=0; 
        }
        else
            return stoi(string(s));
    }while(!ok);
    return -1;
}

void citire_cuvant(char s[1000]){
    bool ok, inceput = 1; int i;
        do{
            cout<<"Răspuns: ";
            cin.getline(s, 999);
            ok=1;
            for(i=0; i<strlen(s) && ok; i++){
                s[i]=tolower(s[i]);
                if(!litera(s[i]) && s[i]!=' '){
                    ok=0;
                    cout<<"Cuvântul nu poate conţine caractere speciale(inclusiv diactritice) sau cifre. \n";
                }
            
            }
            if(strlen(s)==0) ok=0;
        }while(!ok);
}

char citire_grila(){
    bool ok; char s[1000]; int v[4], i;
    do{
        cout<<"Introduceţi varianta a, b, c sau d: ";
        cin.getline(s, 999);
        ok=1;
        v[0]=v[1]=v[2]=v[3]=0;
        for(i=0; i<strlen(s) && ok; i++){
            s[i]=tolower(s[i]);
            if(!litera(s[i]) && !cifra(s[i]) == 1){
                strcpy(s+i, s+i+1);
                i--;
            }
            if(cifra(s[i]) || !strchr("abcd", s[i]))
                ok=0;
            v[s[i]-'a']=1;
        }
        if(v[0]+v[1]+v[2]+v[3]!=1)
            ok=0;
        if(!ok)
            cout<<endl<<"Nu există aceasta opţiune. Încercaţi din nou.\n";
    }while(!ok);
    return s[0];
}

bool check_ans(int rx, char rc, char rs[50], int mode){
    bool corect=0;
    if(mode==1){
        int x;
        x= citire_numar();
        if (x==rx){
            cout<<"Raspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Raspuns greşit! Varianta corectă era "<<rx<<"."<<endl<<endl;
            
    }else if(mode==2){
        char s[1000];
        citire_cuvant(s);
        if(strstr(s, rs)){
            cout<<"Răspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Răspuns greşit! Varianta corectă era \""<<rs<<"\"."<<endl<<endl;
    }
    else if(mode==3){
        char c;
        c=citire_grila();
        if (c==rc){
            cout<<"Răspuns corect!"<<endl<<endl;
            corect=1;
        }
        else 
            cout<<"Răspuns greşit! Varianta corectă era "<<rc<<")."<<endl<<endl;
    }
    
    ecran_nou(4); 
    return corect;
}

float sround(float var){
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void test(){
    
    float score=0, nota;
    char c_null=' ', s_null[50]=" ", rs[50]; 
    titlu("Exerciţii şi probleme pentru fixarea cunoştinţelor");
    cout<<"Acest test conţine 12 itemi.\n\n";
    cout<<"Apăsaţi tasta \"Enter\" pentru a trece la prima întrebare.\n";
    cin.getline(rs,49);
    ecran_nou(2);
//1
    cout<<"1. Care este gradul maxim posibil pentru un nod dintr-un arbore cu 10 noduri?"<<endl;
    if(check_ans(9, c_null, s_null, 1))
        score++;
//2
    cout<<"2. Scrieţi cuvântul care completează enunţul: Într-un graf neorientat, muchia (a,b) este [...] cu un vârfurile a şi b.  \n";
    strcpy(rs, "incidenta");
    if (check_ans(0, c_null, rs , 2))
        score++;
//3
    cout<<"3. Câte grafuri neorientate, distincte, cu 4 vârfuri, se pot construi? Două grafuri se consideră distincte dacă matricele lor de adiacenţă sunt diferite."<<endl;
    cout<<" a) 24 \n b) 4 \n c) 4^6  \n d) 2^6 \n";
    if (check_ans(0, 'd', s_null, 3))
        score++;
//4
    cout<<"4. Se consideră graful neorientat cu 8 noduri, numerotate de la 1 la 8, şi muchiile [1,2], [1,6], [1,7], [2,3], [2,6], [3,6], [3,4], [4,5], [4,8], [5,6], [7,8]. Care este gradul minim al unui nod din acest graf?"<<endl;
    if (check_ans(2, c_null, s_null, 1))
        score++;
//5    
    cout<<"5. Fie n un număr natural impar mai mare decât 2 şi G un graf neorientat cu n noduri, în care fiecare nod este adiacent cu exact n-1 noduri. Graful G este întotdeauna (în afară de conex):"<<endl;
    strcpy(rs, "eulerian");
    if (check_ans(0, c_null, rs , 2))
        score++;
//6    
    cout<<"6. Matricea de adiacenţă a unui graf neorientat G are numărul valorilor de 1 egal cu jumătate din numărul valorilor de 0. Care dintre numerele de mai jos poate fi numărul de noduri ale grafului G?"<<endl;
    cout<<" a) 11 \n b) 12 \n c) 13 \n d) 14 \n";   
    if (check_ans(0, 'b', s_null, 3))
        score++;
//7    
    cout<<"7. Se consideră un graf neorientat G cu 12 noduri şi 7 muchii. Care este numărul maxim de componente conexe din care poate fi format graful G?"<<endl;
    if (check_ans(8, c_null, s_null, 1))
        score++;
//8    
    cout<<"8. Cum se numeşte un graf neorientat în care există drum între oricare două vârfuri?  \n";
    strcpy(rs, "conex");
    if (check_ans(0, c_null, rs , 2))
        score++;
//9    
    cout<<"9. Într-un graf neorientat cu 20 muchii, fiecare nod al grafului are gradul un număr nenul. Doar patru dintre noduri au gradul un număr par, restul nodurilor având gradele numere impare."<<endl;
    cout<<"Care este numărul maxim de noduri pe care poate să le aibă graful? (Introduceţi varianta a, b, c sau d)\n";
    cout<<" a) 36 \n b) 32 \n c) 16 \n d) 10 \n";
    if (check_ans(0, 'a', s_null, 3))
        score++;
//10    
    cout<<"10. Se consideră graful neorientat definit prin mulţimea vârfurilor {1,2,3,4,5,6} şi mulţimea muchiilor {[1,2],[2,3],[3,4],[3,5],[4,5],[1,3],[2,6],[2,4],[4,6]}."<<endl;
    cout<<"Care este numărul minim de muchii ce pot fi eliminate astfel încât graful parţial obţinut să nu mai fie conex?\n";
    if (check_ans(2, c_null, s_null, 1))
        score++;
//11    
    cout<<"11. Cum se numeşte un drum care vizitează o singură dată toate vârfurile unui graf?\n";
    strcpy(rs, "hamiltonian");
    if (check_ans(0, c_null, rs , 2))
        score++;
//12    
    cout<<"12. Care este numărul de muchii care trebuie eliminate dintr-un graf neorientat, complet, cu 7 noduri, astfel încât graful parţial obţinut să fie arbore?"<<endl;
    cout<<" a) 1 \n b) 15 \n c) 6 \n d) 21 \n";
    if (check_ans(0, 'b', s_null, 3))
        score++;
//nota
    cout<<endl;
    nota = sround(score/12)*10;
    cout<<"Aţi obtinut nota "<<nota<<"/10 ("<<score<<"/12 răspunsuri corecte)"<<endl;
    if (score>=8)
        cout<<"Felicitări! \n";
    else if(score>=5)
        cout<<"Mai încercaţi! Sunteţi pe drumul cel bun!\n";
    else if(score>=0)
        cout<<"Of! Mai încercaţi!\n";
    
    ecran_nou(3);
    meniu_prin();
}

void meniu_prin(){
    cout<<"\n1.  Definiţii"<<endl;
    cout<<"2.  Gradul unui vârf"<<endl;
    cout<<"3.  Metode de reprezentare"<<endl;
    cout<<"4.  Parcurgere"<<endl;
    cout<<"5.  Conexitate"<<endl;
    cout<<"6.  Graf hamiltonian"<<endl;
    cout<<"7.  Graf eulerian"<<endl;
    cout<<"8.  Aplicaţii"<<endl;
    cout<<"9.  Test"<<endl;
    cout<<"10. Ieşire"<<endl;
    int opt = select(10);
    ecran_nou(2);
    switch(opt) {
        case 1:
            definitii();
            break;
        case 2:
            grad();
            break;
        case 3:
            met_repr();
            break;
        case 4:
            parcurgeri();
            break;
        case 5:
            conex();
            break;
        case 6:
            hamilton();
            break;
        case 7:
            euler();
            break;
        case 8:
            aplicatii();
            break;
        case 9:
            test();
            break;
        case 10:
            iesire();
            break;
        default:
            meniu_prin();
    }
}

int main() {
    introducere();
    return 0; 
}

 
