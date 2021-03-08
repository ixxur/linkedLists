#include <iostream>

using namespace std;

/// CLASA NOD
class Nod
{
protected:
    int info;
    Nod* next;
    static int contor;         ///numara toate obiectele de tip Nod si Nod_dublu
    static int contor_double;  ///numara doar obiectele de tip Nod_dublu

public:
    Nod ();
    Nod (int);
    Nod (Nod&);
    virtual ~Nod ();
    virtual void citire(istream& in);
    virtual void afisare(ostream &out);
    friend istream& operator >> (istream& in, Nod& n);
    friend ostream& operator << (ostream& out, Nod& n);
    Nod& operator = (Nod&);
    virtual void set_info (int x) ///setter
    {
        info = x;
    };
    virtual int get_info ()      ///getter
    {
        return info;
    };
    virtual void set_next (Nod* n) ///setter
    {
        next = n;
    };
    virtual Nod* get_next ()       ///getter
    {
        return next;
    };
    static void nrNoduri ()       ///metoda care numara nodurile simple
    {
        cout<<contor;
    }
    static int nrNoduriDuble();  ///metoda care numara nodurile duble
    int get_type(Nod *n);        ///metoda care ne spune daca un obiect este de tipul Nod sau Nod_dublu
};

///constructor de initializare fara parametrii
Nod :: Nod ()
{
    contor++;
    this->info = 0;
    this->next = nullptr;
}

///constructor de initializare cu parametrii
Nod :: Nod (int x)
{
    contor++;
    this->info = x;
    this->next = nullptr;
}

///constructor de copiere
Nod :: Nod (Nod& n)
{
    contor++;
    this->info = n.info;
    this->next = n.next;
}

///destructor
Nod :: ~Nod()
{
    this->info = 0;
    this->next = nullptr;
    contor--;
}

///supraincarcare pe >>
istream& operator >> (istream& in, Nod& n)
{
    n.citire(in);
    return in;
}

///supraincarcare pe <<
ostream& operator << (ostream& out, Nod& n)
{
    n.afisare(out);
    return out;
}

///supraincarcare operator de atribuire
Nod& Nod :: operator = (Nod& n)
{
    info = n.info;
    next = n.next;
}

void Nod :: citire (istream& in)
{
    cout<<"Introduceti continutul nodului: ";
    in>>info;
}

void Nod :: afisare (ostream& out)
{
    out<<info<<" ";
}

/// CLASA NOD_DUBLU
class Nod_dublu : public Nod
{
protected:
    Nod_dublu* ante;
    Nod_dublu* next;

public:
    Nod_dublu();
    Nod_dublu(int);
    Nod_dublu(Nod_dublu&);
    ~Nod_dublu();
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator >> (istream&, Nod_dublu&);
    friend ostream& operator << (ostream&, Nod_dublu&);
    Nod_dublu& operator = (Nod_dublu&);
    void set_info (int x)     ///setter
    {
        info = x;
    };
    int get_info ()           ///getter
    {
        return info;
    };
    void set_next (Nod_dublu* n)  ///setter
    {
        next = n;
    };
    Nod_dublu* get_next ()      ///getter
    {
        return next;
    };
    void set_ante (Nod_dublu* n)  ///setter
    {
        ante = n;
    }
    Nod_dublu* get_ante ()    ///getter
    {
        return ante;
    }
    static int nrNoduriDuble()  ///metoda care numara toate obiectele de tip Nod_dublu
    {
        return contor_double;
    }
};

///constructor de initializare fara parametrii
Nod_dublu :: Nod_dublu () : Nod()  ///apelam constructorul din clasa baza
{
    contor_double++;
    this->ante = nullptr;
    this->next = nullptr;
}

///Constructor de initializare cu parametrii
Nod_dublu :: Nod_dublu (int x) : Nod(x)   ///apelam contructorul din clasa baza si adugam ce mai avem de adaugat
{
    contor_double++;
    this->ante = nullptr;
    this->next = nullptr;
}

///destructor
Nod_dublu :: ~Nod_dublu()
{
    this->info = 0;
    this->next = nullptr;
    this->ante = nullptr;
    contor_double--;
}

///supraincarcare pe >>
istream& operator >> (istream& in, Nod_dublu& n)
{
    n.citire(in);
    return in;
}

///supraincarcare pe <<
ostream& operator << (ostream& out, Nod_dublu& n)
{
    n.afisare(out);
    return out;
}
 ///supraincarcare operator de atribuire
Nod_dublu& Nod_dublu :: operator = (Nod_dublu& n)
{
    info = n.info;
    next = n.next;
    ante = n.ante;
}

void Nod_dublu :: citire (istream& in)
{
    Nod :: citire(in);
}

void Nod_dublu :: afisare (ostream& out)
{
    Nod :: afisare(out);
}

///initializarea variabilelor statice
int Nod :: contor = 0;
int Nod :: contor_double = 0;
int Nod :: get_type(Nod *n) ///verifica daca n este un obiect de tip Nod(returneaza 0) sau  Nod_dublu(returneaza 1) - Downcasting/Upcasting
{
    if(dynamic_cast<Nod_dublu*> (n))
        return 1;
    return 0;
}

/// CLASA LDI
class LDI
{
protected:
    Nod_dublu *first;
    Nod_dublu *last;
    int sz;            ///sz = marimea unei liste(nr de noduri pe care il contine)
    static int nr;     ///nr = numarul de total de liste
    static int nrs;    ///nrs = numarul de liste simplu inlantuite

public:
    LDI();
    LDI(int);
    LDI(LDI&);
    ~LDI();
    friend istream& operator >> (istream&, LDI&);
    friend ostream& operator << (ostream&, LDI&);
    LDI& operator = (LDI&);
    virtual void citire (istream& in);
    virtual void afisare (ostream& out);
    virtual void set_first(Nod_dublu*);
    Nod_dublu* get_first();
    virtual void set_last (Nod_dublu*);
    Nod_dublu* get_last ();
    virtual void add_first(int);
    virtual void add_last(int);
    virtual void remove_first();
    virtual void remove_last();
    virtual int get_Size();
    virtual int is_Empty();
    void sortList();
    static void get_nrListe()     ///metoda care returneaza numarul total de liste
    {
        cout<<nr;
    }
    int get_type(LDI*);   ///metoda care returneaza tipul unei liste: 0 pentru LDI si 1 pentru LSI
};

///Constructor de initializare fara parametrii
LDI :: LDI()
{
    sz = 0;
    first = last = nullptr;
    nr++;
}

///Constructor de initializare cu parametru
LDI :: LDI (int x)
{
    Nod_dublu* aux = new Nod_dublu;
    aux->set_info(x);
    first = last = aux;
    sz = 1;
    nr++;
}

///constructor de copiere
LDI :: LDI(LDI& L)
{
    first = L.first;
    last = L.last;
    sz = L.sz;
    nr++;
}

///Destructor
LDI :: ~LDI()
{
    Nod_dublu *p = first;
    while(p != nullptr)
    {
        Nod_dublu *q = p;
        p = p->get_next();
        delete q;
    }
    sz = 0;
}

///supraincarcare pe >>
istream& operator >> (istream& in, LDI& L)
{
    L.citire(in);
    return in;
}

///supraincarcare pe <<
ostream& operator << (ostream& out, LDI& L)
{
    L.afisare(out);
    return out;
}

void LDI :: citire(istream& in)
{
    int n, x;
    cout<<"Introduceti numarul de elemente din lista: ";
    in>>n;
    cout<<"Introduceti elementele: ";
    for(int i = 0; i<n; i++)
    {
        in>>x;
        add_last(x);  ///citim nodul si il adaugam la capatul listei
    }
}

void LDI :: afisare(ostream& out)
{
    Nod_dublu* aux = first;
    while(aux != nullptr)
    {
        out<<*aux<<" ";
        aux = aux->get_next();
    }
}

///metoda pentru returnarea lungimii unei liste
int LDI :: get_Size()
{
    return sz;
}

///metoda care verifica daca lista este goala: returneaza 0 daca da si 1 in caz contrar
int LDI :: is_Empty()
{
    if (sz == 0) return 0;
    else return 1;
}

///setter pentru primul nod
void LDI :: set_first (Nod_dublu* nod)
{
    first = nod;
}

///getter pentru primul nod
Nod_dublu* LDI :: get_first()
{
    return first;
}

///setter pentru ultimul nod
void LDI :: set_last(Nod_dublu* nod)
{
    last = nod;
}

///getter pentru ultimul nod
Nod_dublu* LDI :: get_last()
{
    return last;
}

///metoda care adauga un nod la sfarsitul listei
void LDI :: add_last(int x)
{
    Nod_dublu* nod = new Nod_dublu(x);
    if(last == nullptr)
    {
        first = last = nod;
        sz++;
    }
    else
    {
        last->set_next(nod);
        nod->set_ante(last);
        last = nod;
        sz++;
    }
}

///metoda care adauga un nod la inceputul listei
void LDI :: add_first(int x)
{
    Nod_dublu *nod = new Nod_dublu(x);
    if(first == nullptr)
    {
        first = last = nod;
        sz++;
    }
    else
    {
        first->set_info(nod->get_info());
        nod->set_next(first);
        first = nod;
        ++sz;
    }
}

///metoda care elimina ultimul nod
void LDI :: remove_last()
{
    if(last != nullptr)
    {
        sz--;
        Nod_dublu *p = last;
        last = last->get_ante();
        last->set_next(nullptr);
        delete p;
    }
}

///metoda care elimina primul nod
void LDI :: remove_first()
{
    if(first != nullptr)
    {
        sz--;
        Nod_dublu *p = first;
        first = first->get_next();
        first->set_ante(nullptr);
        delete p;
    }
}

///metoda pentru sortarea unei LDI
void LDI :: sortList()
{
    if(this->get_Size() < 2)  ///daca lista are mai  putin de 2 noduri o returnam deoarece nu avem ce sorta
        return;

    int pos = 0;

    Nod_dublu *first2 = nullptr;
    Nod_dublu *last2 = nullptr;

    while(pos < sz)  ///cat timp nu am ajuns la ultimul nod
    {
        int mini = 1e9;     ///initializam mini cu un numar foarte mare
        Nod_dublu *curr;    ///nodul curent
        Nod_dublu *p = first;
        while(p != nullptr)      ///incepem parcurgerea listei
        {
            if(p->get_info() < mini)    ///daca valoarea nodului p < mini
            {
                mini = p->get_info();   ///mini ia valoarea nodului p
                curr = p;               ///se copiaza in ndul curent, nodul p
            }
            p = p->get_next();
        }                              ///dupa terminarea while-ului vom avea in curr cel mai mic nod care inca se mai afla in lista
        if(pos == 0)
        {
            if(curr == first)         ///daca curr este chiar primul nod, first va lua valoarea urmatorului nod
                first = first->get_next();

            first2 = last2 = curr;    ///initializam nodurile ajutatoare first2 si last 2 cu nodul curent, first 2 devenind cel mai mic nod din lista, iar last2 urmand sa fiecel mai mare dupa terminarea programului
            if(curr->get_ante() != nullptr)   ///daca curr nu este primul nod
                curr->get_ante()->set_next(curr->get_next());  ///legam nodul anterior de nodul catre care pointa curr
            if(curr->get_next() != nullptr)   ///daca curr nu este ultimul nod
                curr->get_next()->set_ante(curr->get_ante());   ///legam nodul din fata lui curr sa pointeze cu ante spre nodul din spatele lui curr

            curr->set_ante(nullptr); ///nodul curent va ramane un nod de sine statator pentru moment
            curr->set_next(nullptr);

            pos++;
        }
        else
        {
            if(curr == first)  ///daca curr este chiar primul nod, first va lua valoarea urmatorului nod
                first = first->get_next();

            if(curr->get_ante() != nullptr)   ///daca curr nu este primul nod
                curr->get_ante()->set_next(curr->get_next());  ///legam nodul anterior de nodul catre care pointa curr
            if(curr->get_next() != nullptr)   ///daca curr nu este ultimul nod
                curr->get_next()->set_ante(curr->get_ante()); ///legam nodul din fata lui curr sa pointeze cu ante spre nodul din spatele lui curr

            curr->set_ante(last2); ///legam last2(ultimul cel mai mic nod gasit anterior din lista) de curr
            curr->set_next(nullptr); ///curr va pointa spre null
            last2->set_next(curr);  ///il legam pe last 2 de curr, last 2 fiind mai mic decat cur
            last2 = curr;  ///last2 ia valoarea lui curr, el fiind cel mai mare dintre nodurile care au fost candva curr, dar cel mai mic dintre nodurile care au ramas a fi curr

            pos++;
        }
    }
    first = first2; ///primul va lua valoarea celui mai mic nod
    last = last2; ///ultimul va lua valoarea celui mai mare nod
}

///CLASA LSI
class LSI : public LDI
{
protected:
    Nod* first;
    Nod* last;
    int sz;        ///lungimea listei

public:
    LSI();
    LSI(int);
    LSI(LSI&);
    ~LSI();
    friend istream& operator >> (istream&, LSI&);
    friend ostream& operator << (ostream&, LSI&);
    LSI& operator = (LSI&);
    void citire (istream& in);
    void afisare (ostream& out);
    void set_first(Nod*);
    void set_last(Nod*);
    Nod* get_first();
    Nod* get_last();
    void add_first(int);
    void add_last(int);
    void remove_first();
    void remove_last();
    int get_Size();
    int is_Empty();
    void get_nrListe()    ///metoda care returneaza numarul de liste simplu inlantuite
    {
        cout<<nrs;
    }
};

///constructor de initializare fara parametrii
LSI :: LSI()
{
    sz = 0;
    first = last = nullptr;
}

///constructor de initialzare cu parametrii
LSI :: LSI(int x)
{
    Nod* p = new Nod (x);
    p->set_info(x);
    first = last = p;
    sz = 1;
    nrs++;
}

///constructor de copiere
LSI :: LSI (LSI& L)
{
    first = L.first;
    last = L.last;
    sz = L.sz;
    nrs++;
}

///Destructor
LSI :: ~LSI()
{
    Nod *p = first;
    while(p!=nullptr)
    {
        Nod *q = p;
        p = p->get_next();
        delete q;
    }
    sz = 0;
}

///supraincarcare pe >>
istream& operator >> (istream& in, LSI& L)
{
    L.citire(in);
    return in;
}

///supraincarcare pe <<
ostream& operator << (ostream& out, LSI& L)
{
    L.afisare(out);
    return out;
}

void LSI :: citire(istream& in)
{
    int n, x;
    cout<<"Introduceti numarul de elemente din lista: ";
    in>>n;
    sz = sz+n;
    cout<<"Introduceti elementele: ";
    for(int i = 0; i<n ; i++)
    {
        in>>x;
        add_last(x);
    }
}

void LSI :: afisare(ostream& out)
{
    Nod* p = first;
    while(p != nullptr)
    {
        out<<*p<<" ";
        p = p->get_next();
    }
}

///metoda care returneaza lungimea listei
int LSI :: get_Size()
{
    return sz;
}

///metoda care verifica daca lista este goala: returneaza 0 daca da si 1 in caz contrar
int LSI :: is_Empty()
{
    if (sz == 0) return 0;
    else return 1;
}

///getter pentru primul nod
Nod* LSI :: get_first()
{
    if(first != nullptr)
        return first;
}

///getter pentru ultimul nod
Nod* LSI :: get_last()
{
    if(last != nullptr)
        return last;
}

///metoda care adauga un nod la finalul listei
void LSI :: add_last(int x)
{
    Nod *nod = new Nod(x);
    if(last == nullptr)
    {
        first = last = nod;
        sz++;
    }
    else
    {
        last->set_next(nod);
        last = nod;
        sz++;
    }
}

///metoda care adauga un nod la inceputul listei
void LSI :: add_first(int x)
{
    Nod *nod = new Nod(x);
    if(first == nullptr)
    {
        first = last = nod;
        sz++;
    }
    else
    {
        nod->set_next(first);
        first = nod;
        ++sz;
    }
}

///metoda care elimina ultimul nod
void LSI :: remove_last()
{
    Nod* p = new Nod;
    while(p->get_next() != nullptr)
        p = p->get_next();
    delete p;
    sz--;
}

///metoda care elimina primul nod
void LSI :: remove_first()
{
    if(first != nullptr)
    {
        sz--;
        Nod *p = first;
        first = first->get_next();
        delete p;
    }
}

///initializarea variabilelor statice
int LDI :: nr = 0;
int LDI :: nrs = 0;
int LDI :: get_type(LDI* L) ///verifica daca L este un obiect de tip LDI(returneaza 0) sau  LSI(returneaza 1) - Downcasting/Upcasting
{
    if(dynamic_cast<LSI*> (L))
        return 1;
    return 0;
}

///functie care adauga si memoreaza n liste, una cate una
void add_lista(LDI **L, int& nr)
{
    cout<<"\n";
    bool choice;
    cout<<"De care lista doriti sa adaugati? (0 - LDI / 1 - LSI)\n";
    cin>>choice;
    if(choice == 0)
        L[nr] = new LDI();
    else L[nr] = new LSI();
    cin>>*L[nr];
    nr++;
}

///output optiuni avansate
void menu_output2()
{
    cout<<"1. Adaugati un nod la inceput";
    cout<<"\n";
    cout<<"2. Aauagati un nod la final";
    cout<<"\n";
    cout<<"3. Eliminati primul nod";
    cout<<"\n";
    cout<<"4. Eliminati ultimul nod";
    cout<<"\n";
    cout<<"5. Vizualizati lista";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

///output principal
void menu_output()
{
    cout<<"\n OPREA ANA-MARIA-RUXANDRA \n";
    cout<<"\n Manipularea listelor simplu si dublu inlantuite utilizand poo \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Adaugati lista";
    cout<<"\n";
    cout<<"2. Vizualizati lista";
    cout<<"\n";
    cout<<"3. Editati lista";
    cout<<"\n";
    cout<<"4. Sortati crescator lista";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

///meniu optiuni avansate pentru modificarea unei anumite liste din array
void menu2(LDI& L)
{
    int option = 0;

    do
    {
        menu_output2();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        cout<<"\n";

        if (option==1)
        {
            int x;
            cout<<"Dati valoarea pe care doriti sa o introduceti: ";
            cin>>x;
            L.add_first(x);
            cout<<"\n";
        }
        if (option==2)
        {
            int x;
            cout<<"Dati valoarea pe care doriti sa o introduceti: ";
            cin>>x;
            L.add_last(x);
            cout<<"\n";

        }
        if (option==3)
        {
            cout<<"Lista dvs dupa eliminarea primului nod: ";
            L.remove_first();
            cout<<L<<"\n";

        }
        if (option==4)
        {
            cout<<"Lista dvs dupa eliminarea ultimului nod: ";
            L.remove_last();
            cout<<L<<"\n";
        }
        if (option==5)
        {
            if(L.get_type(&L) == 1)
                cout<<"Lista LSI "<<": "<<L<<"\n";
            else if(L.get_type(&L) == 0) cout<<"Lista LDI "<<": "<<L<<"\n";

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

///meniu principal
void menu()
{
    int option;
    option=0;
    int nr = 0;  ///numarul initial de liste
    LDI* L[10];  ///array de liste

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        cout<<"\n";

        if (option==1)
        {
            int n;
            cout<<"Introduceti numarul de liste pe care doriti sa il adaugati: ";
            cin>>n;
            while(n)
            {
                add_lista(L, nr);
                n--;
            }
        }
        if (option==2)
        {
           for(int i = 0; i<nr; i++)
            {
                if(L[i]->get_type(L[i]) == 1)
                    cout<<"Lista LSI "<<i<<": "<<*L[i]<<"\n";
                else if(L[i]->get_type(L[i]) == 0)
                    cout<<"Lista LDI "<<i<<": "<<*L[i]<<"\n";
            }

        }
        if (option==3)
        {
            int x;
            cout<<"Ce lista doriti sa modificati?\n";
            for(int i = 0; i<nr; i++)
            {
                if(L[i]->get_type(L[i]) == 1)
                    cout<<"Lista LSI "<<i<<": "<<*L[i]<<"\n";
                else if(L[i]->get_type(L[i]) == 0) cout<<"Lista LDI "<<i<<": "<<*L[i]<<"\n";
            }
            cin>>x;
            menu2(*L[x]);

        }
        if (option==4)
        {
            int x;
            for(int i = 0; i<nr; i++)
            {
                if(L[i]->get_type(*L) == 1)
                    cout<<"Lista LSI "<<i<<": "<<*L[i]<<"\n";
                else if(L[i]->get_type(L[i]) == 0) cout<<"Lista LDI "<<i<<": "<<*L[i]<<"\n";
            }
            cout<<"Ce lista doriti sa sortati?\n";
            cin>>x;
            (*L[x]).sortList();
            cout<<(*L[x]);
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>4)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}


int main()
{
    menu();

 /*   ///exemplu upcasting
    LDI* x = new LSI;
    cin>>*x;
    cout<<*x<<"\n";
    if(x->get_type(x) == 1)
        cout<<"Lista introdusa se comporta ca o LSI\n";
*/

/*   ///exemplu downcasting
   LSI* y = (LSI*) new LDI;
   cin>>*y;
   cout<<*y<<"\n";
   if(y->get_type(y) == 0)
        cout<<"Lista introdusa se comporta ca o LDI\n";
*/


    return 0;
}
