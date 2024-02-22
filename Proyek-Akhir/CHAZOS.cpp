#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;

//Lokasi file eksternal
string dataplayer = "AkunTersimpan/";
string dataplayerstat = "AkunTersimpan/statusplayer/";
string datamonster = "Monster/";
string datacerita = "Cerita/";
string datagambar = "Gambar/";

//Deklarasi eksternal
string garis1 (201,'=');
string garis2 (201,'-');

string pagar (200,'-');

ifstream read,gambar;
ofstream write;

string namamonster[2][5] = {
{"slime", "Werewolf", "basilik", "Chimera", "medusa"},
{"Minotaur", "Siren", "Harpy", "Cyclops", "Cerberus"},
};

int cdplayer[4];
int cdmonster[4];

//Deklarasi struct
struct dataitem{

    string nama;
    string deskripsi;
    int harga;
};

struct developer{

    int i = 0;
    bool mode = false;

}dev;

struct dataplayers{

    string nama;
    string pass;
    int medal;
    int lastlevel;
    int laststage;
    int coin;

    bool giliran;

    struct statusplayer{

        int hp;
        int mana;

        int maxhp;
        int maxmana;

        struct skl{

            string nama;
            int dmg;
            int cost;
            int cooldown;

        }skill[4];

    }playerstat;

}player;

struct mons{

    string nama;
    bool giliran;

        struct statusmonster{

        int hp;
        int mana;

        int maxhp;
        int maxmana;

        struct skl{

            string nama;
            int dmg;
            int cost;
            int cooldown;

        }skill[4];

    }monstat;

}monster;

struct image{

    void locked(){

        cout << "                                                                                               :JGBBBBBBBB5~      " << endl;
        cout << "                                                                                              7@@@@@@@@@@@@@B     " << endl;
        cout << "                                                                                              G@@&       J@@@.    " << endl;
        cout << "                                                                                              G@@#       7@@@.    " << endl;
        cout << "                                                                                              B@@&       J@@@:    " << endl;
        cout << "                                                                                           @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@\033[31m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@\033[31m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@\033[31m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                           @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        
    }
    
    void unlock(){

        cout << "                                                                                                :JGBBBBBBBB5~      " << endl;
        cout << "                                                                                               7@@@@@@@@@@@@@B     " << endl;
        cout << "                                                                                               G@@&       J@@@.    " << endl;
        cout << "                                                                                               G@@#       7@@@.    " << endl;
        cout << "                                                                                                          J@@@:    " << endl;
        cout << "                                                                                            @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@\033[32m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@\033[32m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@\033[32m@@@\033[0m@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@@@@@@@@@@@@@7 " << endl;
        cout << "                                                                                            @@@@@@@@@@@@@@@@@@@@@7 " << endl;

    }

    void judul() {
                                                                                                            
    cout <<"                                                             !Y~  .!77^      !77^        :?.       .777777777777.       !5!               .!Y~     "<<endl;  
    cout <<"                                                          .?B@@@? :&@@Y     .&@@5        G@P       ^@@@@@@@@@@@Y      ~P@@@G~          .!5&@@&!    "<<endl;  
    cout <<"                                                        :J#@@&Y^  :&@@Y     .#@@5       Y@@@?      .~~~~~^5@@@J     ^5@@&G&@@P^     .!5#@@&G7:     "<<endl;  
    cout <<"                                                      ^5&@@B?:    :&@@J      #@@5      7@@@@@~           7@@@J    :Y&@@P^ ^P@@@5:  ^B@@@@J.        "<<endl;  
    cout <<"                                                   .!G@@&P!       :&@@B555555&@@5     ~@@@G@@#.         ?@@@J   .J&@@G!     ~G@@&Y: .?B@@&5^       "<<endl;  
    cout <<"                                                   ~#@@@G^        :&@@@@@@@@@@@@5    :#@@5 G@@P        7@@@Y    ?@@@&~       ^#@@@Y    !G@@@G!     "<<endl;  
    cout <<"                                                     !G@@@P!      :&@@Y.:::.^#@@5    G@@#^.!@@@J      7@@@Y      ^P@@@5:   :Y&@@G~       ^5@@@B?:  "<<endl;  
    cout <<"                                                       ~P@@@B?.   :&@@J     .#@@5   Y@@@@&@&@@@@~    7@@@J         ~G@@&J:?&@@B!        .!5@@@&P~  "<<endl;  
    cout <<"                                                         ^Y&@@#Y^ :&@@Y     .#@@5  7@@@PYYYYYB@@#:  7@@@#JJJJJJ!     !B@@&@@B7       :?P&@@&P7.    "<<endl;  
    cout <<"                                                           :J#@&7 .#@@J     .#@@Y :#@@G      ^@@@5 !&@&&@@@@@@@Y       7#@#?.        ^#@&P7.       "<<endl;  
    cout <<"                                                            .~.   :::.      :::.  :^!:       ~~:. ::::::::::::.        .!.           .~:           "<<endl; 
    }

    struct gambardadu{
    void dadu1(){
        cout << "&@&#&&&&&#&&&&&&&&&&&#&@@\n&@.                   .@@\n&@.                    @@\n&@.                   .@@\n&@.       G&@&G       .@@\n&@.      G@@@@@B      .@@\n&@.       5&&&P       .@@\n&@.                   .@@\n&@.                    @@\n&@:                   .@@\n&@&&&&&&&&&&&&&&&&&&&&&@&\n" << endl;
    }

    void dadu2(){
        cout << "&@&&&&&&&&&&&&&&&&&&&&&&@\n@@                     &@\n@@                     #@\n@@.                    #@\n@@.  .7J7:     :7J!.   #@\n@@. 7@@@@@5   P@@@@@!  #@\n@@. Y@@@@@B   #@@@@@J  #@\n@@.  ^5G5!     !PG5^   #@\n@@.                    #@\n@@                     #@\n@@.                    &@\n@@&&&&&&&&&&&&&&&&&&&&&@@\n" << endl;
    }

    void dadu3(){
        cout << "@@&&&&&&&&&&&&&&&&&&&&&@@\n@&               J5J   &@\n@&             5@@@@@B &@\n@&             7@@@@@# &@\n@&         J5J   JP5   &@\n@&       5@@@@@P       &@\n@&       5@@@@@P       &@\n@&   J5J   J5J         &@\n@& 7@@@@&P             &@\n@& &@@@@@G             &@\n@&   J5J               &@\n@@&&&&&&&&&&&&&&&&&&&&&@@\n" << endl;
    }
    
    void dadu4(){
        cout << "@@&&&&&&&&&&&&&&&&&&&&&@@\n@@                     @@\n@&  J&@&#~     ~#&@&J  &@\n@& !@@@@@@.   .@@@@@@! &@\n@&  G@@@&J     J&@@@G  &@\n@&                     &@\n@&  P@@@&?     ?&@@@P  &@\n@& !@@@@@@.   .@@@@@@! &@\n@&  Y&@@&!     !&@@&Y  &@\n@&                     &@\n@@&&&&&&&&&&&&&&&&&&&&&@@\n" << endl;
    }

    void dadu5(){
        cout << "@@&&&&&&&&&&&&&&&&&&&&&@@\n@@  P##P         P##P  @@\n@& @@@@@@.     .@@@@@@ &@\n@& &@@@@&.     .&@@@@&.&@\n@&  ^77^   YGGY  ^77^  &@\n@&       :@@@@@@.      &@\n@&       .&@@@@#       &@\n@&  ^77^   ^77:  ^77^  &@\n@&.&@@@@&.     .&@@@@&.&@\n@&:@@@@@@.     :@@@@@@:&@\n@@.^P##P^       ^P##P^.@@\n@@&&&&&&&&&&&&&&&&&&&&&@@\n" << endl;
    }

    void dadu6(){
        cout << "@@&&&##&&##&&&##&&##&&&@@\n@&   .5#&G^   ^G&#5.   &@\n@&   Y@@@@&   &@@@@Y   &@\n@&    !PGJ.   .JGP!    &@\n@&                     @&\n@&    7GGY.   .YGG7    &@\n@&   5@@@@&   &@@@@5   &@\n@&    JGB5:   :5BGJ    &@\n@&                     @&\n@&    ~5P?.   .?P5~    &@\n@&   Y@@@@&   &@@@@Y   &@\n@&   .P&&B~   ~B&&P.   &@\n@@###BB##BB###BB##BB###@@\n" << endl;
    }
};

gambardadu dadu;

}img;


//Deklarasi fungsi

void header();
void logo();
void file_error(string x);
void login();
void regis();
void menuawal();

void mainmenu();
void journey();
void tavern();
void about();
void importstatus();
void importmonster(string namamonster[][5]);
void statusbar();

void underworld(bool *players, bool *monsters);
void playernyerang(bool *players, bool *monsters);
void monsternyerang(bool *players, bool *monsters);
void hasilakhir(bool *players, bool *monsters);
void cekdarah(bool *players, bool *monsters);
void cerita();
void lempardadu(bool *players,bool *monsters);
void tampilkandadu(int x);

void tampilkangambar(string nama);
void kurangicooldown(int cd[]);
void savedata();
void bubblesort(dataitem a[],int max, int pilih);
void tambahdarah(dataitem a[],int pilih);
void tambahmana(dataitem a[],int pilih);
void tambahmaxhp(dataitem a[],int pilih);
void tambahmaxmana(dataitem a[],int pilih);
void savestatus();
void saveplayer();

void barplayer();
void tamat();
void ceritaend();

int main(){

    menuawal();
    
}

void file_error(string x){
    
    header();

    cout << "\033[31m[ FILE ERROR ! ]\033[0m" << endl;
    cout << "=========================================================" << endl;
    cout << x << " tidak ditemukan !" << endl << endl;
    getch();

    menuawal();

}

void logo(){
    cout << "   G@@7  qYp    qYp      q@@@@p.  q@p    q@@p     qBGp     7###GYp.       q@@@@@@p     ~YPG57p.     \n   &@@#  #@&.   &@G   ^B@@&GB&@@P @@@^   Y@@#    5@@@@:   .@@@&&@@@J    G@@@@@@@@@@B   !@@@B#@@G    \n   #@@&  B@@:  :@@5  Y@@G.    q!p @@@~   Y@@&   ?@@!&@&.  .@@&  .J@@5  @@@5^.   :5@@@5 ?@@7  .&@G   \n   #@@&  B@@:  !@@Y !@@P          @@@:   Y@@&  :@@J ^@@G  .@@&    5@@ @@@:        :@@@ 7@@7   #@&   \n   B@@&  B@@?  P@@7 G@@:          @@@&GGB@@@#  B@@@&&@@@~ .@@&    7@@ @@P          5@@ 7@@5^7#@@p   \n   G@@&  ^&@@@@@@G  P@@:          @@@G??7B@@#  @@@Y!!#@@#  @@&    B@& @@&.        .&@@ 7@@@@@@P     \n   B@@@Y   ^?YY?^   :@@#:    :YB! &@@.   7@@B G@@#   ^@@@  @@&  .G@@  P@@@J.    .?@@@G ?@@G?@@@?    \n   P@@@@@@@@@@@@@&:  :B@@&GG&@@P  @@@.   7@@# @@@~    B@@G &@@&&@@P    !#@@@@&&@@@@#!  7@@?  J@@&~  \n   7YPPPPPPGBBBBG?     :@@@@:     @@@    7@@# @@@      @@@ D@@@@^        .!5G##G57.    7PB^   .J#5p  "<< endl;
}

void header(){

    system("cls");
    img.judul();
    cout << garis1 << endl << endl;

}

void regis(){

    int i = 0;

    //Deklarasi
    string saveduser;
    string tempuser;
    string temppass;

    //UI1
    header();
    cout << "\033[1m[ Registrasi ]\033[0m" << endl << endl;

    cout << "Username : ";
    getline(cin,tempuser);

    cout << "Password : ";
    cin >> temppass;
    cin.ignore();


    string fileplayer = dataplayer + "dataplayer.txt";
    string filestatus = dataplayerstat + tempuser + "stat.txt";

    //Pencegahan username kembar
        read.open(fileplayer);
        if(!read.is_open()){
            file_error(fileplayer);
        }
        else{

            //Pencegahan username kembar
            while(getline(read,player.nama,',') && getline(read,player.pass,',') && read >> player.medal && read >> player.lastlevel && read >> player.laststage && read >> player.coin && read.ignore()){

                //Monitoring data player
                if (dev.mode == true){

                    cout  << endl << "[ Data ke- "<< i++ << " ]" << endl;
                    cout << "Username     : " << player.nama << endl;
                    cout << "Password     : " << player.pass << endl;
                    cout << "Medali       : " << player.medal << endl;
                    cout << "Last level   : " << player.lastlevel << endl;
                    cout << "Last stage   : " << player.laststage << endl;
                    cout << "Coin         : " << player.coin << endl;
                    getch();
                }

                //Terjadinya proses pembandingan
                if (player.nama == tempuser){

                    cout << garis2 << endl;
                    cout << "\033[31m>> Mohon maaf, username ini sudah digunakan <<\033[0m" << endl;
                    getch();
                    read.close();
                    menuawal();
                }
            }
                read.close();
                
        }

            //Jika bebas dari looping tersebut, berarti user bisa membuat akun
            write.open(fileplayer,ios::app);
            write << tempuser << "," << temppass << ",0 0 0 0" << endl;
            write.close();

            write.open(filestatus);
            write << "100 100" << endl;
            write << "100 100" << endl;
            write << "Basic attack,5 0 0" << endl;
            write << "Skill : Lightning Spear,20 15 1" << endl;
            write << "Skill : Regeneration,30 40 3" << endl;
            write << "Ultimate Skill : Zeus Judgement,50 20 4" << endl;
            write.close();

            cout << garis2 << endl;
            cout << "\033[32mSelamat akun anda berhasil dibuat, silahkan login !\033[0m" << endl;
            getch();

        

    menuawal();
}
    
void login(){

    //Deklarasi internal
    string tempuser;
    string temppass;


    header();
    img.locked();
    cout << "\033[1m[ Login ]\033[0m" << endl;
    cout << garis2 << endl;

    cout << "Username : ";
    cin >> tempuser;

    cout << "Password : ";
    cin >> temppass;
    cin.ignore();

    string fileplayer = dataplayer + "dataplayer.txt";

    read.open(fileplayer);
    
    if (!read.is_open()){
        file_error(fileplayer);
    }


    if(dev.mode == true){
        header();
        cout << "Data yang \033[32mtelah disimpan\033[0m  dari : \033[1m" << fileplayer  << "\033[0m"<< endl;
        cout << garis2 << endl;
    }

    //proses ngecek data player menggunakan metode sequential nonsentinal search
    while (getline(read,player.nama,',') && getline(read,player.pass,',') && read >> player.medal && read >> player.lastlevel && read >> player.laststage && read >> player.coin && read.ignore()){
        
        //Monitoring data player
        if (dev.mode == true){
            cout << endl << "[ Data akun ] " << endl;
            cout << "Username   : " << player.nama << endl;
            cout << "Password   : " << player.pass << endl;
            cout << "Medali     : " << player.medal << endl;
            cout << "Last level : " << player.lastlevel << endl;
            cout << "Last stage : " << player.laststage << endl;
            cout << "Coin       : " << player.coin << endl;

            getch();
        }

        //Terjadinya proses pembandingan
        if (player.nama == tempuser && player.pass == temppass){

            header();
            img.unlock();

            cout << "\033[1m[ Login ]\033[0m" << endl;
            
            cout << endl << garis2 << endl;
            cout << "Selamat datang kembali \033[32m" << player.nama << "\033[0m !" << endl;

            getch();
            read.close();
            mainmenu();
        }
    }
    
    //Jika berhasil lolos dari loopingan tersebut, berarti akun anda tidak terdaftar
    read.close();

    cout << endl << garis2 << endl;
    cout << "\033[31m>> Maaf username atau password salah ! <<\033[0m" << endl;

    getch();
    menuawal();

}

void menuawal(){

    //Deklarasi
    int pilih;

    //UI
    header();
    cout << "\033[1m[ Selamat datang di CHAZOS ! ]\033[0m" << endl << endl;

    //Pengaktifan developer mode
    if (dev.i >= 5){
       dev.mode = true;

       cout << "\033[1m> Developer mode \033[32mON\033[0m <\033[0m" << endl << endl;
    }//Mematikan developer mode
    else if(dev.i == 0){
        dev.mode = false;
    }
    
    cout << "1. Login" << endl;
    cout << "2. Registrasi" << endl;
    cout << "3. Exit" << endl << endl;

    cout << garis2 << endl;
    cout << "Pilih 1-3 : ";
    pilih = getch();


    //Login
    if (pilih == 49){
        login();
    }
    else if(pilih == 50){
        regis();
    }
    else if(pilih == 51){
        cout << "Terima kasih sudah bermain, sampai jumpa !" << endl;
        exit(0);

    }
    else if(pilih == 52){
        
        //Syarat menghidupkan developer mode
        dev.i++;

        //Syarat mematikan developer mode
        if (dev.mode == true){
            dev.i = 0;
        }
        
        menuawal();

    }
    else{

        menuawal();

    }
    
}

void mainmenu(){

    //Melakukan import data status player
    importstatus();
    srand(time(NULL));

    int pilih;

    header();

    cout << "\033[1m[ Menu Utama ]\033[0m" << endl << endl;

    cout << "1. Journey " << endl;
    cout << "2. Tavern petualang" << endl;
    cout << "3. About" << endl;
    cout << "4. Log out" << endl << endl;

    cout << garis2 << endl;
    cout << "Pilih 1-4 : ";
    pilih = getch();

    switch (pilih)
    {
    case 49:

        if (player.lastlevel ==  2 && player.laststage == 0){
        }
        

        journey();
        break;

    case 50:
        tavern();
        break;

    case 51:
        about();
        break;

    case 52:
        menuawal();
        break;
    
    default:
        mainmenu();
        break;
    }
}

void journey(){
    
    //agar rand() hasilnya bervariasi
    bool *players = new bool;
    bool *monsters = new bool;

    srand(time(NULL));

    header();

    importmonster(namamonster);
    cerita();
    
    //Berperang
    lempardadu(players,monsters);
    underworld(players,monsters);
}

void barplayer(){
    
    cout << setw(90) << "" << "\033[1m\033[32m[ Status " << player.nama << " ]\033[0m" << endl << endl;
    cout << setw(86) << "" << "\033[1m[ Coin anda : \033[32m" << player.coin  << " Coin\033[0m\033[1m ]\033[0m" << endl << endl;
    cout << setw(80) << "" << "----------------------------------" << endl;
    cout << setw(90) << "" << "Darah    : " << setw(15) << left  << player.playerstat.hp << endl;
    cout << setw(90) << "" << "Mana     : " << setw(15) << left  << player.playerstat.mana << endl;
    cout << setw(90) << "" << "Max HP   : " << setw(15) << left  << player.playerstat.maxhp << endl;
    cout << setw(90) << "" << "Max Mana : " << setw(15) << left  << player.playerstat.maxmana << endl << endl << endl;

}

void tavern(){

    int i = 0;

    dataitem item[10];

    //Hanya import sekali ketika pertama kali memulai
    read.open("Tavern/item.txt");
    while(getline(read,item[i].nama,',') && getline(read,item[i].deskripsi,',') && read >> item[i].harga && read.ignore()){
        i++;
    };
    read.close();

    string filegambar = "bartender" + to_string(rand() % 2);

    header();
    tampilkangambar(filegambar);
    cout << garis1 << endl;

    
    cout << "----------------------" << endl;
    cout << setw(5) << left << "|\033[1m" << setw(20) << "Bar Staff" << setw(2) << "\033[0m|" << endl;
    cout << pagar << endl;
    cout << setw(2)  << "|"  << setw(197) << "Selamat datang di Tavern Petualang, Selamat berbelanja ! " <<  setw(2) << "|" << endl;
    cout << pagar << endl << endl;

    getch();


    ulangi:
    system("cls");
    tampilkangambar("suasanabar");
    cout << garis1 << endl << endl;


    barplayer();
	cout<<setw(35)<<""<<setw(133)<<setfill('=')<<""<<setfill(' ')<<endl;
	cout << setw(35) << "" <<setw(3)<<"|"<< setw(3) << "NO" << setw(3) << "|" << setw(60) << left << "Nama item" << setw(3) <<  "|" << setw(60) << "Harga"<<setw(3)<<"|"<<endl;
	cout<<setw(35)<<""<<setw(133)<<setfill('=')<<""<<setfill(' ')<<endl;
	for (int j = 0; j < i; j++)
    {
		cout << setw(35) << "" <<setw(3)<<"|"<< setw(3) << j+1 << setw(3) << "|" <<setw(60) << left << item[j].nama << setw(3) <<  "|" << setw(5) << item[j].harga << setw(55) << "Coins" <<setw(3)<<"|"<<endl;
    }
	cout<<setw(35)<<""<<setw(133)<<setfill('=')<<""<<setfill(' ')<<endl << endl;
    cout << garis2 << endl;

    cout << setw(36) << "" << "6. Urutkan Berdasarkan A-Z" << endl;
    cout << setw(36) << "" << "7. Urutkan Berdasarkan harga" << endl;
    cout << setw(36) << "" << "8. Exit" << endl << endl;
    

    int pilih;
    cout << setw(100) << "" << "Pilih 1-8 : ";
    cin >> pilih;
    pilih--;

    if(pilih == 5){
        bubblesort(item,i,pilih);
        goto ulangi;
    }
    else if(pilih == 6){
        bubblesort(item,i,pilih);
        goto ulangi;
    }
    else if(pilih == 7){
        mainmenu();
    }
    else if (item[pilih].nama == "Potion of Healing"){
        tambahdarah(item,pilih);
    }
    else if(item[pilih].nama == "Tavern Burger"){
        tambahmaxhp(item,pilih);
    }
    else if(item[pilih].nama == "Elven Leaf Wine"){
        tambahmana(item,pilih);
    }
    else if(item[pilih].nama == "Pixie Nectar"){
        tambahdarah(item,pilih);
    }
    else if (item[pilih].nama == "Wizard's Elixir"){
        tambahmaxmana(item,pilih);
    }
    else{
        goto ulangi;
    }
    

}

void tambahdarah(dataitem a[],int pilih){
    
    //Healing Potion
    char x;

    header();
    if (a[pilih].nama == "Pixie Nectar"){
        tampilkangambar("honey");
    }
    else if(a[pilih].nama == "Potion of Healing"){
        tampilkangambar("healingpotion");
    }

    cout << garis1 << endl << endl;

    cout << "\033[1m[ Deskripsi item ] : " << endl;

    cout << garis2 << endl;
    cout << setw(3) << "|" << setw(197) << a[pilih].deskripsi  << setw(3) << "|" << endl;
    cout << garis2 << endl << endl;

    cout << setw(60) << "" << "Apakah anda yakin ingin membeli \033[32m" << a[pilih].nama << "\033[0m dengan harga \033[1m" << a[pilih].harga << " Coin's\033[0m (Y/N) ? : ";
    cin >> x;

    x = toupper(x);

    if(x == 'Y' && player.coin < a[pilih].harga ){

        header();
        tampilkangambar("stop");
        cout << garis2 << endl << endl;

        cout << setw(77) << "" << "\033[31m>> Mohon maaf, tetapi coin anda kurang ! <<\033[0m" << endl;
        getch();
    }
    else if (x == 'Y' && player.coin > a[pilih].harga ){ 

        player.coin -= a[pilih].harga;
        player.playerstat.hp += 50;

        if (player.playerstat.hp > player.playerstat.maxhp){
            player.playerstat.hp = player.playerstat.maxhp;
        }
        

        header();
        tampilkangambar("player5");
        cout << garis1 << endl << endl;

        cout << setw(60) << "" << "Darahmu baru saja teregenerasi sebanyak \033[32m+50\033[0m setelah mengonsumsi \033[1m" << a[pilih].nama << "\033[0m";
        getch();
        
    }
    
    savedata();
    tavern();
}

void tambahmana(dataitem a[],int pilih){

    //Elven Leaf Wine
    char x;

    header();
    tampilkangambar("wine");
    cout << garis1 << endl << endl;

    cout << "\033[1m[ Deskripsi item ] : " << endl;

    cout << garis2 << endl;
    cout << setw(3) << "|" << setw(197) << a[pilih].deskripsi  << setw(3) << "|" << endl;
    cout << garis2 << endl << endl;

    cout << setw(60) << "" << "Apakah anda yakin ingin membeli \033[32m" << a[pilih].nama << "\033[0m dengan harga \033[1m" << a[pilih].harga << " Coin's\033[0m (Y/N) ? : ";
    cin >> x;

    x = toupper(x);

    if(x == 'Y' && player.coin < a[pilih].harga ){

        header();
        tampilkangambar("stop");
        cout << garis2 << endl << endl;

        cout << setw(77) << "" << "\033[31m>> Mohon maaf, tetapi coin anda kurang ! <<\033[0m" << endl;
        getch();
    }
    else if (x == 'Y' && player.coin > a[pilih].harga){ 

        player.coin -= a[pilih].harga;
        player.playerstat.mana += 50;

        if (player.playerstat.mana > player.playerstat.maxmana){
            player.playerstat.mana = player.playerstat.maxmana;
        }

        header();
        tampilkangambar("player5");
        cout << garis1 << endl << endl;

        cout << setw(60) << "" << "Mana-mu baru saja teregenerasi sebanyak \033[32m+50\033[0m setelah mengonsumsi \033[1m" << a[pilih].nama << "\033[0m";
        getch();
        
    }

    savedata();
    tavern();

}

void tambahmaxhp(dataitem a[],int pilih){

    //Tavern Burger
    char x;

    header();
    tampilkangambar("burgerinvert");
    cout << garis1 << endl << endl;

    cout << "\033[1m[ Deskripsi item ] : " << endl;

    cout << garis2 << endl;
    cout << setw(3) << "|" << setw(197) << a[pilih].deskripsi  << setw(3) << "|" << endl;
    cout << garis2 << endl << endl;

    cout << setw(60) << "" << "Apakah anda yakin ingin membeli \033[32m" << a[pilih].nama << "\033[0m dengan harga \033[1m" << a[pilih].harga << " Coin's\033[0m (Y/N) ? : ";
    cin >> x;

    x = toupper(x);
    
    if(x == 'Y' && player.coin < a[pilih].harga ){

        header();
        tampilkangambar("stop");
        cout << garis2 << endl << endl;

        cout << setw(77) << "" << "\033[31m>> Mohon maaf, tetapi coin anda kurang ! <<\033[0m" << endl;
        getch();
    }
    else if (x == 'Y' && player.coin > a[pilih].harga){ 

        player.coin -= a[pilih].harga;
        player.playerstat.maxhp += 20;


        header();
        tampilkangambar("player5");
        cout << garis1 << endl << endl;

        cout << setw(60) << "" << "Batas maksimal darahmu baru saja bertambah sebanyak \033[32m+20\033[0m setelah mengonsumsi \033[1m" << a[pilih].nama << "\033[0m";
        getch();
        
    }

    savedata();
    tavern();

}

void tambahmaxmana(dataitem a[],int pilih){

    //Wizard Elixir
    char x;

    header();
    tampilkangambar("wizardelixir");
    cout << garis1 << endl << endl;

    cout << "\033[1m[ Deskripsi item ] : " << endl;

    cout << garis2 << endl;
    cout << setw(3) << "|" << setw(197) << a[pilih].deskripsi  << setw(3) << "|" << endl;
    cout << garis2 << endl << endl;

    cout << setw(60) << "" << "Apakah anda yakin ingin membeli \033[32m" << a[pilih].nama << "\033[0m dengan harga \033[1m" << a[pilih].harga << " Coin's\033[0m (Y/N) ? : ";
    cin >> x;

    x = toupper(x);

    if(x == 'Y' && player.coin < a[pilih].harga ){

        header();
        tampilkangambar("stop");
        cout << garis2 << endl << endl;

        cout << setw(77) << "" << "\033[31m>> Mohon maaf, tetapi coin anda kurang ! <<\033[0m" << endl;
        getch();
    }
    else if (x == 'Y' && player.coin > a[pilih].harga ){ 
        player.coin -= a[pilih].harga;
        player.playerstat.maxmana += 20;

        header();
        tampilkangambar("player5");
        cout << garis1 << endl << endl;

        cout << setw(60) << "" << "Batas maksimal mana-mu baru saja bertambah sebanyak \033[32m+20\033[0m setelah mengonsumsi \033[1m" << a[pilih].nama << "\033[0m";
        getch();
        
    }
    
    savedata();
    tavern();

}

void bubblesort(dataitem a[],int max, int pilih){

    for (int i = 0; i < max - 1; i++){
        for (int j = 0; j < max - i - 1; j++){

            if (pilih == 6){

                    if(a[j].harga > a[j+1].harga){
                        //swap(a[j].nama,a[j+1].nama);
                        //swap(a[j].harga,a[j+1].harga);

                        swap(a[j],a[j+1]);
                    }

            }
            else if(pilih == 5){

                    if(a[j].nama > a[j+1].nama){
                        //swap(a[j].nama,a[j+1].nama);
                        //swap(a[j].harga,a[j+1].harga);
                        swap(a[j],a[j+1]);
                    }
            }
            
        }
        
    }
}

void about(){

    header();
    tampilkangambar("end");

    string fileaboutjourney = datacerita + "aboutjourney.txt";

    read.open(fileaboutjourney);
    while(getline(read,fileaboutjourney)){
    cout << fileaboutjourney << endl;
    }
    read.close();

    getch();
    

    mainmenu();
}

void importstatus(){

    string filedataplayer = dataplayerstat + player.nama + "stat.txt";


    read.open(filedataplayer);

    if (!read.is_open()){
        file_error(filedataplayer);
    }

    //Proses import status player
    read >> player.playerstat.hp >> player.playerstat.mana;
    read >> player.playerstat.maxhp >> player.playerstat.maxmana;

    if(dev.mode == true){
        header();
        cout << "Data yang \033[32mberhasil\033[0m di import dari : \033[1m" << filedataplayer  << "\033[0m"<< endl;
        cout << garis2 << endl;
    }
    for (int i = 0; i < 4; i++){
        
        read.ignore();
        getline(read,player.playerstat.skill[i].nama,',');
        read >> player.playerstat.skill[i].dmg;
        read >> player.playerstat.skill[i].cost;
        read >> player.playerstat.skill[i].cooldown;
        
        cdplayer[i] = player.playerstat.skill[i].cooldown;
        

        
        if (dev.mode == true){

            cout << endl << "Skill ke-" << i << endl;
            cout << "Nama       : " << player.playerstat.skill[i].nama << endl;
            cout << "Damage     : " << player.playerstat.skill[i].dmg << endl;
            cout << "Cost       : " << player.playerstat.skill[i].cost << endl;
            cout << "Cooldown   : " << player.playerstat.skill[i].cooldown << endl;
            cout << "Temp CD    : "  << cdplayer[i] << endl;

        }
        
    }

    if(dev.mode == true){
    getch();
    }

    read.close();
}

void importmonster(string namamonster[][5]){

    string filedatamonster = datamonster + "Level-" + to_string(player.lastlevel) + "/" + namamonster[player.lastlevel][player.laststage] + ".txt";


    read.open(filedatamonster);

    if (!read.is_open()){
        file_error(filedatamonster);
    }

    //Proses import status monster
    getline(read,monster.nama);
    read >> monster.monstat.hp >> monster.monstat.mana;
    read >> monster.monstat.maxhp >> monster.monstat.maxmana;

    if (dev.mode == true){

        header();
        cout << "Data yang \033[32mberhasil\033[0m di import dari : \033[1m" << filedatamonster  << "\033[0m"<< endl;
        cout << garis2 << endl;

        cout << "Nama monster : " << monster.nama << endl;
        cout << "Darah        : " << monster.monstat.hp << endl;
        cout << "Mana         : " << monster.monstat.mana << endl;
        cout << "Max darah    : " << monster.monstat.maxhp << endl;
        cout << "Max mana     : " << monster.monstat.maxmana << endl;

    }


    for (int i = 0; i < 4; i++){
        
        read.ignore();
        getline(read,monster.monstat.skill[i].nama,',');
        read >> monster.monstat.skill[i].dmg;
        read >> monster.monstat.skill[i].cost;
        read >> monster.monstat.skill[i].cooldown;

        cdmonster[i] = monster.monstat.skill[i].cooldown;
        
        if (dev.mode == true){

            cout << endl << "Skill ke-" << i << endl;
            cout << "Nama       : " << monster.monstat.skill[i].nama << endl;
            cout << "Damage     : " << monster.monstat.skill[i].dmg << endl;
            cout << "Cost       : " << monster.monstat.skill[i].cost << endl;
            cout << "Cooldown   : " << monster.monstat.skill[i].cooldown << endl;
            cout << "Temp CD    : "  << cdmonster[i] << endl;

        }
        
    }

    if(dev.mode == true){
    getch();
    }

    read.close();
}

void underworld(bool *players, bool* monsters){

    static int i = 0;

    header();
    statusbar();

    cout << "Giliran ke-" << i++ << endl << endl;

    if(*players == true){
        playernyerang(players,monsters);
    }
    else if(*monsters == true){
        monsternyerang(players,monsters);
    }

    underworld(players,monsters);

}

void playernyerang(bool *players, bool *monsters){
    int p = rand() % 2;
    int x;

        /*=============================================================  User Interface =============================================================*/
        header();

        if (p == 1){
            tampilkangambar("player6");
        }
        else if(p == 0){
            tampilkangambar("player");
        }
        statusbar();

        cout << "[ Pilih jenis serangan anda ! ]" << endl << endl;

        //Info skill player dan pemilihan skill untuk bertarung
        for (int i = 0; i < 4; i++){

            if(player.playerstat.skill[i].nama == "Skill : Regeneration"){
                cout << i+1 << ". \033[32m" << player.playerstat.skill[i].nama << "\033[0m" << endl;
                cout << "-------------------------------------------------------"<<endl;
                cout << "   [Informasi serangan]" << endl;
                cout << "   Heal      : \033[32m" << player.playerstat.skill[i].dmg << "\033[0m" << endl;
                cout << "   Mana cost : " << player.playerstat.skill[i].cost << endl;

                if(cdplayer[i] > 0 ){
                    cout << "   Cooldown  : \033[31m" << cdplayer[i]  <<"\033[0m giliran lagi"<< endl << endl;
                }
                else if(cdplayer[i] == 0){
                    cout << "   Cooldown  : \033[32mREADY !\033[0m" << endl << endl;
                }
            }
            else{
                cout << i+1 << ". \033[32m" << player.playerstat.skill[i].nama << "\033[0m" << endl;
                cout << "-------------------------------------------------------"<<endl;
                cout << "   [Informasi serangan]" << endl;
                cout << "   Damage    : \033[31m" << player.playerstat.skill[i].dmg << "\033[0m" << endl;
                cout << "   Mana cost : " << player.playerstat.skill[i].cost << endl;

                if(cdplayer[i] > 0 ){
                    cout << "   Cooldown  :\033[31m " << cdplayer[i] << "\033[0m giliran lagi" << endl << endl;
                }
                else if(cdplayer[i] == 0){
                    cout << "   Cooldown  : \033[32mREADY !\033[0m " << endl << endl;
                }

            }
        }
        cout << "5. \033[32m[ Lewati giliran menyerang ]\033[0m" << endl;
        cout << "------------------------------------"<<endl;
        cout << "   [Informasi pilihan]" << endl;
        cout << "   \033[31mTidak akan menyerang selama 1 giliran\033[0m" << endl << endl;

        cout << garis2 << endl;
        cout << "Pilih 1-5 : ";
        cin >> x;
        x -= 1;


        /*=============================================================  Mekanisme =============================================================*/
        if(x >= 0 && x <= 5){
            

            /*------------------------------------Skill spesial------------------------------------*/
            if (x == 4){

                //Skill skip
                header();
                tampilkangambar("balaraja");
                statusbar();

                cout << "                                                       >> Kamu memilih untuk melewati giliran menyerang, saatnya giliran monster menyerang ! <<" << endl;
                getch();

                *monsters= true;
                *players = false ;

                kurangicooldown(cdplayer);

                cekdarah(players,monsters);
                underworld(players,monsters);
            }
            else if((x * 2) % 10 == 8 && player.playerstat.skill[x].nama != "Skill : Regeneration"){
                
                //Skill miss
                header();
                tampilkangambar("player2");
                statusbar();

                cout << "                                                         >> Kamu menyerang dengan skill \033[32m]" << player.playerstat.skill[x].nama << "\033[0m, tetapi " << monster.nama << "sangat lincah,ia dapat \033[31mmenghindari serangan\033[0m tersebut ! <<"<< endl;
                getch();

                *monsters= true;
                *players = false;
                
                cekdarah(players,monsters);
                underworld(players,monsters);
            }
            /*------------------------------------Skill spesial------------------------------------*/
            

            /*------------------------------------Skill biasa & regen------------------------------------*/
            if(cdplayer[x] > 0){

                header();
                tampilkangambar("stop");
                statusbar();
                cout << endl << endl << "                                                                                     \033[31m>> SKILL MASIH COOLDOWN ! <<\033[0m" << endl;
                getch();
                playernyerang(players,monsters);     
            }
            else if(player.playerstat.skill[x].cost > player.playerstat.mana){

                header();
                tampilkangambar("stop");
                statusbar();

                cout << endl << endl << "                                                                                     \033[31m>> Mana anda tidak cukup ! <<\033[0m" << endl;
                getch();
                playernyerang(players,monsters);
            }
            else{
                
                //Regenerasi
                if(player.playerstat.skill[x].nama == "Skill : Regeneration"){
                    
                    player.playerstat.hp += player.playerstat.skill[x].dmg;

                    //Pengendalian HP agar tidak melebihi max HP player
                    if (player.playerstat.hp > player.playerstat.maxhp){
                        player.playerstat.hp =  player.playerstat.maxhp;
                    }

                    player.playerstat.mana -= player.playerstat.skill[x].cost;

                    header();
                    tampilkangambar("player7");
                    statusbar();

                    cout << "                                                         >> Kamu menggunakan \033[32m" << player.playerstat.skill[x].nama << "\033[0m dan me-regenerasi darahmu sebesar \033[32m+" << player.playerstat.skill[x].dmg << "\033[0m <<"<<endl;
                    getch();

                    *monsters = true;
                    *players = false;

                    cekdarah(players,monsters);
                    kurangicooldown(cdplayer);
                    cdplayer[x] = player.playerstat.skill[x].cooldown;
                    underworld(players,monsters);

                }

                //Skill normal
                else{

                    monster.monstat.hp -= player.playerstat.skill[x].dmg;

                    //Pengendalian agar darah monster tidak minus
                    if (monster.monstat.hp < 0){
                        monster.monstat.hp = 0;
                    }
                }

                player.playerstat.mana -= player.playerstat.skill[x].cost;
                /*------------------------------------Skill biasa & regen------------------------------------*/

                
        /*=============================================================  User Interface =============================================================*/
                header();
                if (x == 3){
                    tampilkangambar("player4");
                }
                else if(x == 1){
                    tampilkangambar("player8");
                }
                else if(x == 0){
                    tampilkangambar("player");
                }
                statusbar();

                cout << "                                                         >> Kamu menggunakan \033[32m" << player.playerstat.skill[x].nama << "\033[0m dan memberikan damage sebesar \033[31m" << player.playerstat.skill[x].dmg << "\033[0m kepada \033[1m" << monster.nama << "\033[0m <<" <<endl;
                getch();

                kurangicooldown(cdplayer);
                //Restart cooldown
                cdplayer[x] = player.playerstat.skill[x].cooldown;

                cekdarah(players,monsters);

                *monsters = true;
                *players = false;
            }

        }
        else{
            playernyerang(players,monsters);
        }
    
    cekdarah(players,monsters);

}

void monsternyerang(bool *players, bool *monsters){

    if(dev.mode == true){
        cout << "Masuk ke monsternyerang();" << endl;
        getch();
    }

    *players = true;
    *monsters = false;
    
    ulangi:
    int x  = rand() % 4 + 1;
    x -= 1;

    if(dev.mode == true){
        cout << "Masuk ke monsternyerang()/Berhasil inisialiasi X;" << endl;
        getch();
    }

    //Autoselect ke basic attack jika mana low
    if (monster.monstat.mana < 2){
        x = 0;

            if(dev.mode == true){
                cout << "Masuk ke monsternyerang()/Berhasil inisialiasi X/Autoselect basic attack;" << endl;
                getch();
            }
    }

    if(dev.mode == true){
        cout << "Masuk ke monsternyerang()/Lepas dari autoselect basic attack" << endl;
        getch();
    }

    //Akan mengulang terus sampai ketemu yang skill cd nya ready
    if (cdmonster[x] > 0){
        if(dev.mode == true){
        cout << "Masuk looping CD" << endl;
        getch();
        goto ulangi;
    }
    }

    if(dev.mode == true){
        cout << "Bebas dari looping cd" << endl;
        getch();
    }

    //Jika mana kurang akan dilakukan pemilihan ulang
    if (monster.monstat.mana < monster.monstat.skill[x].cost){

    if(dev.mode == true){
        cout << "Masuk looping mana" << endl;
        getch();
    }
        goto ulangi;
    }

    if(dev.mode == true){
        cout << "Bebas looping mana" << endl;
        getch();
    }
    

    //Memberikan damage kepada player & memotong mana sesuai harga skill
    player.playerstat.hp -= monster.monstat.skill[x].dmg;
    monster.monstat.mana -= monster.monstat.skill[x].cost;
    if (monster.monstat.mana < 0){
        monster.monstat.mana = 0;
    }
    

    /*=============================================================  User Interface =============================================================*/
    header();
    tampilkangambar(monster.nama);
    statusbar();

    cout << "                                                         >> " << monster.nama << " menggunakan \033[32m" << monster.monstat.skill[x].nama << "\033[0m dan memberikan damage sebesar \033[31m" <<  monster.monstat.skill[x].dmg << "\033[0m kepada \033[1manda\033[0m <<" <<endl;
    getch();

    //restart cooldown
    cdmonster[x] = monster.monstat.skill[x].cooldown;

    if(player.playerstat.hp < 0 ){
        player.playerstat.hp = 0;
    }

    kurangicooldown(cdmonster);
    cdmonster[x] = monster.monstat.skill[x].cooldown;
    cekdarah(players,monsters);


    
}

void kurangicooldown(int cd[]){

        for (int i = 0; i < 4; i++) {
            if (cd[i] > 0) {
                cd[i]--;
                if(cd[i] < 0){
                    cd[i] = 0;
                }
            }
        }
}

void hasilakhir(bool *players, bool  *monsters){

    int x = rand() % 3;
    int pilih;

    int basereward = ((player.laststage + 1) * 5 + player.lastlevel);
    int luckyreward = (rand() % 50);
    int hpreward = 0;
    if (player.playerstat.hp > 50){
        hpreward =  player.playerstat.hp / 2 ;
    }

        if(*players == true){
        
        //================================================================ Reward ====================================================
            int coin =   basereward + luckyreward + hpreward;
            player.coin += coin;

            header();
            tampilkangambar("victory");
            statusbar();

            cout << "\033[1m[ Level : " << player.lastlevel << " ]\033[0m" << endl;
            cout <<"\033[1m[ Stage : " << player.laststage << " ]\033[0m"<< endl << endl;
            
            //ucapan selamat random berdasarkan variabel X
            if(x == 0){
                cout << "                                                             \033[32m>> Kamu menang, ya kamu menang, pertarungan tadi sungguh menakjubkan ! <<\033[0m" << endl;
            }
            else if(x == 1){
                cout << "                                                          \033[32m>> Selamat, kamu memenangkan pertarungan dengan mudah melawan " << monster.nama << " ! <<\033[0m" << endl;
            }
            else if(x == 2){
                cout << "                                                            \033[32m>> Pertarungan yang bagus, siap menghadapi monster berikut nya ? <<\033[0m" << endl << endl << endl;;
            }
            cout << endl <<  "                                                 \033[1mRound reward :\033[0m" << endl;
            cout << "                                                 \033[32mBase reward +" << basereward << " Coin's\033[0m" << endl;
            cout << "                                                 \033[32mLucky reward +" << luckyreward << " Coin's\033[0m" << endl;
            
            if (player.playerstat.hp > 50){
            cout << "                                                 \033[32mUntouched reward +" << hpreward << " Coin's, dapat menyelesaikan pertarungan dengan darah tersisa sebanyak " << player.playerstat.hp << " HP !\033[0m" << endl << endl;
            }
            cout << endl << "                                                 Kamu mendapatkan sebanyak \033[32m+" << coin << " Coin's\033[0m,dan dapat digunakan untuk berbelanja di \033[1mTavern Petualang\033[0m !" << endl;


            //===================================================== User Interface ======================================================
            cout << garis2 << endl;
            cout << endl << endl;
            cout << "1. Kembali ke menu awal" << endl;

            if(player.lastlevel == 1 && player.laststage == 4){
                cout << "2. Tamat."<< endl;
            }
            else{
                cout << "2. Lanjut ke level dan stage berikutnya" << endl;
            }
            
            if(player.laststage > 0){
            cout << "3. Kembali ke stage sebelumnya"<< endl;
            }


            //Jika level sudah mencapai 2 tidak akan terjadi apa apa
            if(player.lastlevel == 1 && player.laststage == 4){
                player.lastlevel = player.lastlevel;
                player.laststage = player.laststage;
            }

            cout << endl;
            cout << "Pilih 1-3 : ";
            cin >> pilih;

            //===================================================== User Interface ======================================================
        }
        else if(*monsters == true){

            header();
            tampilkangambar("Ainz");
            statusbar();

            if(x == 0){
                cout << "                                                                         \033[31m>> Kamu kalah, kamu mati dengan mengenaskan <<\033[0m" << endl;
            }
            else if(x == 1){
                cout << "                                                                        \033[31m>> Belum cukup kuat, berlatihlah lebih keras ! <<\033[0m" << endl;
            }
            else if(x == 2){
                cout << "                                                     \033[31m>> Terlalu cepat 100 tahun untuk mengalahkan " << monster.nama << ", berlatihlah lebih keras ! <<\033[0m" << endl;
            }

            cout << endl << endl;
            cout << "1. Kembali ke menu awal" << endl;
            cout << "2. Mengulangi level dan stage ini" << endl;

            if (player.laststage > 0){
            cout << "3. Kembali ke stage sebelumnya" << endl;
            }

            cout << garis2 << endl;
            cout << "Pilih 1-3 : ";
            cin >> pilih;
    
        }

        //Restart giliran
        *players = false;
        *monsters = false;

        savedata();

        if (pilih == 1){
            mainmenu();
        }
        else if(pilih == 2){

            if(player.lastlevel == 1 && player.laststage == 4){
                tamat();
            }
            else{

                //Jika stage sudah mentok sampai 4, level akan bertambah dan mengembalikan stage menjadi 0
                if (player.laststage == 4){
                    player.lastlevel++;
                    player.laststage = 0;
                }
                else{
                    player.laststage++;
                }

                //Darah reset kalau player sekarat
                if(player.playerstat.hp == 0){
                        player.playerstat.hp += 50;
                        player.playerstat.mana += 20;
                }

                savedata();
                journey();

            }
        }
        else if(pilih == 3 && player.laststage > 0){

            //Jika stage sudah mentok sampai 0, level akan berkurang dan mengembalikan stage menjadi 4
            if (player.laststage == 0)
            {
                player.lastlevel--;
                player.laststage = 4;
            }else if (player.lastlevel > -1 && player.laststage > 0){
                player.laststage--;
            }

            savedata();
            journey();
        }
        else{
            hasilakhir(players,monsters);
        }
        
}

void tamat(){

    header();
    tampilkangambar("end");
    cout << garis1 << endl;

    ceritaend();

    about();
}

void ceritaend(){
    
    int x = 0;
    int skip;

    string filecerita = "Cerita/End/Tamat.txt";
    string line,nama;

    read.open(filecerita);


    if (dev.mode == true){

        header();
        cout << "Data yang \033[32mberhasil\033[0m di import dari : \033[1m" << filecerita  << "\033[0m"<< endl;
        cout << garis2 << endl;
    }



    while (!read.eof()){

        header();


            if(x % 2 == 0){

                getline(read,nama,':') && getline(read,line);

                tampilkangambar(nama);
                cout << garis2 << endl;

                cout << "----------------------" << endl;
                cout << setw(5) << left << "|\033[1m" << setw(20) << nama << setw(2) << "\033[0m|" << endl;
                cout << pagar << endl;
                cout << setw(2)  << "|"  << setw(197) << line <<  setw(2) << "|" << endl;
                cout << pagar << endl << endl;

                cout << "Tekan spasi 2 kali untuk melewati cerita.." << endl;

                skip = getch();
                if (skip == 32){
                    break;
                }
            }
            else{

                getline(read,nama,':') && getline(read,line);

                tampilkangambar(nama);
                cout << garis1 << endl;

                cout << setw(178) << "" << setw(20) << "----------------------" << endl;
                cout << setw(178) << "" << setw(7) << "|\033[1m" << setw(18) << right << player.nama << setw(2) << "\033[0m|"  << endl;
                cout << pagar << endl;
                cout << setw(1)  << "|"  << setw(197) << line <<  setw(2) << "|" << endl;
                cout << pagar << endl << endl;

                cout << "Tekan spasi 2 kali untuk melewati cerita.." << endl;

                skip = getch();
                if (skip == 32){
                    break;
                }
            
            }

            x++;

    }
    read.close();
    getch();
    
}

void cekdarah(bool *players, bool *monsters){
    
    if(player.playerstat.hp < 1){
        *players = false;
        *monsters = true;
        hasilakhir(players,monsters);

    }
    else if(monster.monstat.hp < 1){
        *players = true;
        *monsters = false;
        hasilakhir(players,monsters);
    }
}

void statusbar(){
    
    cout << garis2 << endl;
    cout << "\033[1m\033[32m[ Status Anda ]\033[0m" << setw(80) << left << "" << setw(3) << "\033[1m|\033[0m" << setw(20) << "\033[1m\033[31m [ Status " << monster.nama << "] \033[0m"<< endl;
    cout << "Darah   : " << setw(15) << left  << player.playerstat.hp << setw(70) << "" << setw(3) << "\033[1m|\033[0m" << setw(10) << left << " Darah   : " << monster.monstat.hp << endl;
    cout << "Mana    : " << setw(15) << left  << player.playerstat.mana << setw(70) << "" << setw(3) << "\033[1m|\033[0m" << setw(10) << left << " Mana    : " << monster.monstat.mana << endl;
    cout << garis2 << endl << endl;
    cout << "                                                                                            \033[1m[ Bertarung ! ]\033[0m" << endl << endl;

}

void cerita(){

    int x = 0;
    int skip;

    string filecerita = datacerita + "Level-" + to_string(player.lastlevel) + "/" + "stage" + to_string(player.laststage) + ".txt";
    string line,nama;

    read.open(filecerita);


    if (dev.mode == true){

        header();
        cout << "Data yang \033[32mberhasil\033[0m di import dari : \033[1m" << filecerita  << "\033[0m"<< endl;
        cout << garis2 << endl;
    }



    while (!read.eof()){

        header();


            if(x % 2 == 0){

                getline(read,nama,':') && getline(read,line);

                tampilkangambar(nama);
                cout << garis2 << endl;

                cout << "----------------------" << endl;
                cout << setw(5) << left << "|\033[1m" << setw(20) << nama << setw(2) << "\033[0m|" << endl;
                cout << pagar << endl;
                cout << setw(2)  << "|"  << setw(197) << line <<  setw(2) << "|" << endl;
                cout << pagar << endl << endl;

                cout << "Tekan spasi 2 kali untuk melewati cerita.." << endl;

                skip = getch();
                if (skip == 32){
                    break;
                }
            }
            else{

                getline(read,nama,':') && getline(read,line);

                tampilkangambar(nama);
                cout << garis1 << endl;

                cout << setw(178) << "" << setw(20) << "----------------------" << endl;
                cout << setw(178) << "" << setw(7) << "|\033[1m" << setw(18) << right << player.nama << setw(2) << "\033[0m|"  << endl;
                cout << pagar << endl;
                cout << setw(1)  << "|"  << setw(197) << line <<  setw(2) << "|" << endl;
                cout << pagar << endl << endl;

                cout << "Tekan spasi 2 kali untuk melewati cerita.." << endl;

                skip = getch();
                if (skip == 32){
                    break;
                }
            
            }

            x++;

    }
    read.close();
    getch();
    
}

void lempardadu(bool *players, bool *monsters){

    int dplayer = (rand() % 6) +1;
    int dmonster = (rand() % 6) +1;

    header();
    cout << "\033[31mPemberitahuan :\033[0m" << endl << endl;
    cout << "Saat melawan monster, andaa diharuskan melempar dadu terlebih dahulu" << endl;
    cout << "Tujuan dari melempar dadu ini digunakan untuk menentukan siapa yang akan menyerang terlebih dahulu" << endl;
    cout << "Lempar dadu ini digunakan hanya sekali saat ingin melawan monster" << endl;
    cout << garis2 << endl;
    
    cout << endl << "\033[1m[ Lempar Dadu ]\033[0m " << endl << endl;

    cout << "Tekan apa saja untuk melempar dadu ! " << endl << endl;
    getch();

    cout << endl << "Anda melempar dadu dan mendapatkan ankga \033[32m" << dplayer << "\033[0m ketika melempar ! " << endl << endl;
    tampilkandadu(dplayer);
    
    cout << endl << "Monster melempar dadu dan mendapatkan angka \033[31m" << dmonster << "\033[0m ketika ia melempar ! " << endl << endl;
    tampilkandadu(dmonster);
    getch();
    
    if(dplayer == dmonster){

        cout << "\033[31m>> Hasil seri, dan akan di adakan pelemparan ulang ! <<\033[0m" << endl;
        getch();
        lempardadu(players,monsters);
    }

    if (dplayer > dmonster){

        cout << garis2 << endl << endl;
        cout << "\033[12m[ Anda mendapat giliran menyerang pertama ! ]\033[0m" << endl;
        getch();

        *players = true;
        *monsters = false;

        underworld(players,monsters);

    }
    else{

        cout << garis2 << endl << endl;
        cout << "\033[1mMonster mendapat giliran menyerang pertama ! \033[0m" << endl;
        getch();


        *players = false;
        *monsters = true;

        underworld(players,monsters);
    }

}

void tampilkandadu(int x){
    
    if (x == 1){
        img.dadu.dadu1();
    }
    else if(x == 2){
        img.dadu.dadu2();
    }
    else if(x == 3){
        img.dadu.dadu3();
    }else if(x == 4){
        img.dadu.dadu4();
    }else if(x == 5){
        img.dadu.dadu5();
    }else if(x == 6){
        img.dadu.dadu6();
    }

}

void tampilkangambar(string nama){

    string filegambar = datagambar + nama + ".txt";
    string line;

    gambar.open(filegambar);

        if (!gambar.is_open()){
            file_error(filegambar);
        }

        while(getline(gambar,line)){
            cout << line << endl;
        }
        
    gambar.close();
}

void savedata(){

    saveplayer();
    savestatus();

}

void savestatus(){

    //======================================================================  Saved Status ======================================================================
    int x = 0;
    string filestatus = dataplayerstat + player.nama + "stat.txt";

    write.open(filestatus);

    write << player.playerstat.hp << " " << player.playerstat.mana << endl;
    write << player.playerstat.maxhp << " " << player.playerstat.maxmana << endl;
    for (int i = 0; i < 4; i++)
    {
        write << player.playerstat.skill[i].nama << "," << player.playerstat.skill[i].dmg << " " << player.playerstat.skill[i].cost << " " << player.playerstat.skill[i].cooldown << endl;
    }
    write.close();
}

void saveplayer(){

    //======================================================================  Save data player ======================================================================

    string fileplayer = dataplayer + "dataplayer.txt";
    dataplayers temp[100];

    int i = 0;

    //Buka file dan menyimpan semua data ke dalam variabel
    read.open(fileplayer);
    if (!read.is_open()){
        file_error(fileplayer);
    }
    while(getline(read,temp[i].nama,',') && getline(read,temp[i].pass,',') && read >> temp[i].medal && read >> temp[i].lastlevel && read >> temp[i].laststage && read >> temp[i].coin && read.ignore()){
        //Monitoring data player sebelum di ubah
        if (dev.mode == true){
            cout << endl << "[ Data akun ke- "<< i << " ]" << endl;
            cout << "Username   : " << temp[i].nama << endl;
            cout << "Password   : " << temp[i].pass << endl;
            cout << "Medali     : " << temp[i].medal << endl;
            cout << "Last level : " << temp[i].lastlevel << endl;
            cout << "Last stage : " << temp[i].laststage << endl;
            cout << "Coin       : " << temp[i].coin << endl;
        }

    i++;
    }
    read.close();

    //Mencari nama yang sama  dengan username di dalam array
    for (int j = 0; j < i; j++){ 
        if(temp[j].nama == player.nama){ 
            //proses saving menggunakan metode sequential nonsentinel
            temp[j].nama = player.nama;
            temp[j].pass = player.pass;
            temp[j].medal = player.medal;
            temp[j].lastlevel = player.lastlevel;
            temp[j].laststage = player.laststage;
            temp[j].coin = player.coin;
        }

        //Monitoring data yg berhasil di ubah
        if (dev.mode == true){
            cout << endl << "[ Data akun ke- "<< j << " ]" << endl;
            cout << "Username   : " << temp[j].nama << endl;
            cout << "Password   : " << temp[j].pass << endl;
            cout << "Medali     : " << temp[j].medal << endl;
            cout << "Last level : " << temp[j].lastlevel << endl;
            cout << "Last stage : " << temp[j].laststage << endl;
            cout << "Coin       : " << temp[j].coin << endl;
        }
    }
    
    //Save data yg tadi di ubah
    write.open(fileplayer);
    for (int j = 0; j < i; j++){
        write << temp[j].nama << "," << temp[j].pass << "," << temp[j].medal << " " << temp[j].lastlevel << " "<< temp[j].laststage << " "<< temp[j].coin << endl;
    }
    write.close();


}