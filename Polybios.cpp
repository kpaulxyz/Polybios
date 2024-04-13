#include <string>
#include <iostream>
#include <cmath>

using namespace std;

char matrix[5][5]={ 
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
string schluessel;
string alphabet = "abcdefghiklmnopqrstuvwxyz";
string klartext;
string chiffretext;

void schluesseleingabe();
void alphabeterstellung();
void matrixerstellung();
void auswahl();
void verschluesseln();
void entschluesseln();

int main() {
    schluesseleingabe();
    alphabeterstellung();
    matrixerstellung();
    auswahl();
}

void schluesseleingabe(){
    cout << "Geben Sie den Schluessel ein: ";
    cin >> schluessel;
    string schluesselneu;
    string schluesselalt = schluessel;
    bool isschluesselneu = 0;
    int i=0;
    for (int y = 0; y<=schluessel.length(); y++){
        for (int x= 0; x<=schluessel.length(); x++){ 
            if (y!=x&&x>y){
                if (schluessel[y]==schluessel[x]){
               isschluesselneu = 1;
               schluessel.erase(y,1);
               }
            }
        }
    }
    for (int y=0; y<=schluessel.length();y++){
        
        if (schluessel[y]!='j'){
            schluesselneu = schluesselneu + schluessel[y];
        }
        else {
            schluesselneu = schluesselneu + 'i';
        }
        

    } 
    schluessel = schluesselneu;
    if (isschluesselneu==1){
        cout << "Schluessel \"" << schluesselalt << "\" war ungueltig und wurde zu \""<< schluessel << "\" gekürtzt.\n";
    }
}

void alphabeterstellung(){
    int y = 0;
    int condition = 25 - schluessel.length();
    while (alphabet.length()+schluessel.length()-1!=25){
        for (int x = 0; x<= schluessel.length(); x++){
            if (alphabet[y]==schluessel[x]) {
                alphabet.erase(y,1);
            }
        }
        y++;
        if (y>alphabet.length()){
            y=0;
        }
    }
}

void matrixerstellung(){
    cout <<"\n";
    int k = 0;
    int i = 0;
    int j = 0;
    int l = 0;
    for (i = 0; i<5;i++){
        for (j = 0; j<5; j++){
            if (k>=schluessel.length()-1){
                matrix[i][j] = alphabet[l];
                l++;
            }
            else {
            matrix[i][j] = schluessel[k];
            k++;
            }
            
        }
        cout << "\n";
    }
    cout <<"\n\n Ihre matrix sieht jetzt so aus: \n";
    for (int y = 0; y<5;y++){
        for (int x = 0; x<5; x++){
            cout << matrix[y][x] << " ";
        }
        cout << "\n";
    }
    cout <<"\n";
}

void auswahl(){
    int auswahl;
    cout << "Wollen Sie ver-(1) oder entschluesseln(2)? ";
    cin >> auswahl;
    switch (auswahl){
        case 1: 
            verschluesseln();
            break;
        case 2: 
            entschluesseln();
            break;
    }
}

void verschluesseln(){
    cout << "Geben Sie den zu Verschlüsselnden Text ein: ";
    cin >> klartext;
    for (int z = 0; z<klartext.length();z++){
        for (int y = 0; y<5;y++){
            for (int x = 0; x<5; x++){
                if (matrix[y][x]==klartext[z]){
                    chiffretext = chiffretext + to_string(y);
                    chiffretext = chiffretext + to_string(x);
                }
            }
        
        }
    }
    cout << "Der Chiffretext lautet: " << chiffretext<< "\n"; 
}

void entschluesseln(){
    cout << "Geben Sie den zu Entschluesselnden Text ein: ";
    cin >> chiffretext;
    int i = 0;
    while (i< chiffretext.length()){
        klartext = klartext + matrix[(int)chiffretext[i]-48][(int)chiffretext[i+1]-48];
        i+=2;
    }
    cout << "Der Klartext lautet: " << klartext<< "\n"; 

}
