//landlord.cpp
//models the finances for an apartment building
#include "landlord.h" //for class declarations, etc.

//////////////////////global functions////////////////////////
void getaLine(string& inStr)    // get line of text
   {
   char temp[21];
   cin.get(temp, 20, '\n');
   cin.ignore(20, '\n');
   inStr = temp;
   }
//--------------------------------------------------------------
char getaChar()                 // get a character
   {
   char ch = cin.get();
   cin.ignore(80, '\n');
   return ch;
   }
//--------------------------------------------------------------

/////////////////////methods for class tenant///////////////////
tenant::tenant(string n, int aNo) : name(n), aptNumber(aNo)
   { /* empty */ }
//--------------------------------------------------------------
tenant::~tenant()
   { /* empty */ }
//--------------------------------------------------------------
int tenant::getAptNumber()
   { return aptNumber; }
//--------------------------------------------------------------
bool operator < (const tenant& t1, const tenant& t2)
   { return t1.name < t2.name; }
//--------------------------------------------------------------
bool operator == (const tenant& t1, const tenant& t2)
   { return t1.name == t2.name; }
//--------------------------------------------------------------
ostream& operator << (ostream& s, const tenant& t)
   { s << t.aptNumber << '\t' << t.name << endl;  return s; }
//-------------------------------------------------------------- 
     
////////////////method for class tenantInputScreen//////////////
void tenantInputScreen::getTenant()       //get tenant info
   {
   cout << "Enter tenant's name (George Smith): ";
   getaLine(tName);
   cout << "Enter tenant's apartment number (101): ";
   cin >> aptNo;        
   cin.ignore(80, '\n');                  //make tenant
   tenant* ptrTenant = new tenant(tName, aptNo);  
   ptrTenantList->insertTenant(ptrTenant); //send to tenant list
   }
////////////////////////////////////////////////////////////////
bool compareTenants::operator () (tenant* ptrT1, 
                                  tenant* ptrT2) const
   { return *ptrT1 < *ptrT2; }
//--------------------------------------------------------------

///////////////////methods for class tenantList/////////////////
tenantList::~tenantList()               //destructor
   {
   while( !setPtrsTens.empty() )        //delete all tenants,
      {                                 //remove ptrs from set
      iter = setPtrsTens.begin();
      delete *iter;
      setPtrsTens.erase(iter);
      }
   }  // end ~tenantList()
//--------------------------------------------------------------
void tenantList::insertTenant(tenant* ptrT)
   {
   setPtrsTens.insert(ptrT);            //insert
   }
//--------------------------------------------------------------      
 int tenantList::getAptNo(string tName) //name on list?
    {
    int aptNo;
    tenant dummy(tName, 0);       
    iter = setPtrsTens.begin();
    while( iter != setPtrsTens.end() )
       {
       aptNo = (*iter)->getAptNumber(); //look for tenant
       if(dummy == **iter++)            //on the list?
          return aptNo;                 //yes
       }
    return -1;                          //no
    }
//--------------------------------------------------------------      
 void tenantList::display()             //display tenant list
    {
    cout << "\nApt#\tTenant name\n-------------------\n";
    if( setPtrsTens.empty() )
       cout << "***No tenants***\n";
    else
       {
       iter = setPtrsTens.begin();
       while( iter != setPtrsTens.end() )
          cout << **iter++;
       }
    }  // end display()
//--------------------------------------------------------------
 
/////////////////////methods for class rentRow//////////////////
rentRow::rentRow(int an) : aptNo(an)    // 1-arg constructor
   { fill( &rent[0], &rent[12], 0); }
//--------------------------------------------------------------
void rentRow::setRent(int m, float am)  
   { rent[m] = am; }
//--------------------------------------------------------------      
float rentRow::getSumOfRow()            // sum of rents in row
   { return accumulate( &rent[0], &rent[12], 0); }
//--------------------------------------------------------------
bool operator < (const rentRow& t1, const rentRow& t2)
   { return t1.aptNo < t2.aptNo; }
//--------------------------------------------------------------
bool operator == (const rentRow& t1, const rentRow& t2)
   { return t1.aptNo == t2.aptNo; }
//--------------------------------------------------------------
ostream& operator << (ostream& s, const rentRow& an)
   { 
   s << an.aptNo << '\t';               //print apartment number
   for(int j=0; j<12; j++)              //print 12 rents
      {
      if(an.rent[j] == 0)
         s << "  0  ";
      else
         s << an.rent[j] << "  ";
      }
   s << endl;
   return s;
   }
////////////////////////////////////////////////////////////////
bool compareRows::operator () (rentRow* ptrR1, 
                               rentRow* ptrR2) const
   { return *ptrR1 < *ptrR2; }

///////////////////methods for class rentRecord/////////////////
rentRecord::~rentRecord()                //destructor
   {
   while( !setPtrsRR.empty() )           //delete rent rows,
      {                                  //remove ptrs from set
      iter = setPtrsRR.begin();
      delete *iter;
      setPtrsRR.erase(iter);
      }
   }
//--------------------------------------------------------------
void rentRecord::insertRent(int aptNo, int month, float amount)
   {
   rentRow searchRow(aptNo);      //temp row with same aptNo      
   iter = setPtrsRR.begin();              //search setPtrsRR
   while( iter != setPtrsRR.end() )
      {
      if(searchRow==**iter)               //rentRow found?
         {                                //yes,
         (*iter)->setRent(month, amount); //put rent in row
         return;
         }
      else
         iter++;
      }                                   //didn't find it
   rentRow* ptrRow = new rentRow(aptNo);  //make new row
   ptrRow->setRent(month, amount);        //put rent in row
   setPtrsRR.insert(ptrRow);              //put row in vector
   }  // end insertRent()         
//--------------------------------------------------------------
void rentRecord::display()
   {
   cout << "\nAptNo\tJan  Feb  Mar  Apr  May  Jun  "
        <<          "Jul  Aug  Sep  Oct  Nov  Dec\n"
        << "---------------------------------"
        << "---------------------------------\n";
   if( setPtrsRR.empty() )
      cout << "***No rents***\n";
   else
      {
      iter = setPtrsRR.begin();
      while( iter != setPtrsRR.end() )
         cout << **iter++;
      }
   }
//--------------------------------------------------------------
float rentRecord::getSumOfRents()     // return sum of all rents
   {
   float sumRents = 0.0;
   iter = setPtrsRR.begin();
   while( iter != setPtrsRR.end() )
      {
      sumRents += (*iter)->getSumOfRow();
      iter++;
      }
   return sumRents;
   }
//--------------------------------------------------------------

/////////////////methods for class rentInputScreen//////////////
void rentInputScreen::getRent()
   {
   cout << "Enter tenant's name: ";
   getaLine(renterName);
   aptNo = ptrTenantList->getAptNo(renterName);
   if(aptNo > 0)                  // if name found,
      {                           // get rent amount
      cout << "Enter amount paid (345.67): ";
      cin >> rentPaid;
      cin.ignore(80, '\n');
      cout << "Enter month rent is for (1-12): ";
      cin >> month;
      cin.ignore(80, '\n');
      month--;                    // (internal is 0-11)
      ptrRentRecord->insertRent(aptNo, month, rentPaid);
      }
   else                           // return
      cout << "No tenant with that name.\n"; 
   }  // end getRent()
//--------------------------------------------------------------

///////////////////methods for class expense////////////////////
bool operator < (const expense& e1, const expense& e2)
   {                               // compares dates
   if(e1.month == e2.month)        // if same month,
      return e1.day < e2.day;      // compare days
   else                            // otherwise,
      return e1.month < e2.month;  // compare months
   }
//--------------------------------------------------------------
bool operator == (const expense& e1, const expense& e2)
   { return e1.month == e2.month && e1.day == e2.day; }   
//--------------------------------------------------------------
ostream& operator << (ostream& s, const expense& exp)
   { 
   s << exp.month << '/' << exp.day << '\t' << exp.payee << '\t' ;             
   s << exp.amount << '\t' << exp.category << endl;
   return s;
   }
//--------------------------------------------------------------

////////////////////////////////////////////////////////////////
bool compareDates::operator () (expense* ptrE1, 
                                expense* ptrE2) const
   { return *ptrE1 < *ptrE2; }
//--------------------------------------------------------------

////////////////////////////////////////////////////////////////
bool compareCategories::operator () (expense* ptrE1, 
                                     expense* ptrE2) const
   { return ptrE1->category < ptrE2->category; }
//--------------------------------------------------------------

//////////////////methods for class expenseRecord///////////////
expenseRecord::~expenseRecord()         //destructor
   {
   while( !vectPtrsExpenses.empty() )   //delete expense objects,
      {                                 //remove ptrs from vector
      iter = vectPtrsExpenses.begin();
      delete *iter;
      vectPtrsExpenses.erase(iter);
      }
   }
//--------------------------------------------------------------
void expenseRecord::insertExp(expense* ptrExp)
   { vectPtrsExpenses.push_back(ptrExp); }
//--------------------------------------------------------------
void expenseRecord::display()
   {
   cout << "\nDate\tPayee\t\tAmount\tCategory\n"
        << "----------------------------------------\n";
   if( vectPtrsExpenses.size() == 0 )
      cout << "***No expenses***\n";
   else
      {
      sort( vectPtrsExpenses.begin(),        // sort by date
            vectPtrsExpenses.end(), compareDates() );
      iter = vectPtrsExpenses.begin();
      while( iter != vectPtrsExpenses.end() )
         cout << **iter++;
      }
   }
//-----------------------------------------------------------
float expenseRecord::displaySummary() // used by annualReport
   {
   float totalExpenses = 0;           //total, all categories

   if( vectPtrsExpenses.size() == 0 )
      {
      cout << "\tAll categories\t0\n";
      return 0;
      }
   // sort by category
   sort( vectPtrsExpenses.begin(),
        vectPtrsExpenses.end(), compareCategories() );
  
   // for each category, sum the entries

   iter = vectPtrsExpenses.begin();
   string tempCat = (*iter)->category;
   float sumCat = 0.0;
   while( iter != vectPtrsExpenses.end() )
      {            
      if(tempCat == (*iter)->category)
         sumCat += (*iter)->amount;   // same category
      else
         {                            // different category
         cout << '\t' << tempCat << '\t' << sumCat << endl; 
         totalExpenses += sumCat;     // add previous category
         tempCat = (*iter)->category;
         sumCat = (*iter)->amount;    // add final amount
         }
      iter++;
      }  // end while
   totalExpenses += sumCat;           // add final category
   cout << '\t' << tempCat << '\t' << sumCat << endl;
   return totalExpenses;
   }  // end displaySummary()
   //-----------------------------------------------------------
   
//////////////methods for class expenseInputScreen//////////////
expenseInputScreen::expenseInputScreen(expenseRecord* per) : 
                            ptrExpenseRecord(per)
   { /*empty*/ }
   //-----------------------------------------------------------
void expenseInputScreen::getExpense()
   {
   int month, day;
   string category, payee;
   float amount;

   cout << "Enter month (1-12): ";
   cin >> month;
   cin.ignore(80, '\n');
   cout << "Enter day (1-31): ";
   cin  >> day;
   cin.ignore(80, '\n');
   cout << "Enter expense category (Repairing, Utilities): ";
   getaLine(category);
   cout << "Enter payee "
        << "(Bob's Hardware, Big Electric Co): ";
   getaLine(payee);
   cout << "Enter amount (39.95): ";
   cin >> amount;
   cin.ignore(80, '\n');
   expense* ptrExpense = new
                expense(month, day, category, payee, amount);
   ptrExpenseRecord->insertExp(ptrExpense);
   }
//-----------------------------------------------------------

//////////////////methods for class annualReport/////////////
annualReport::annualReport(rentRecord* pRR, 
                           expenseRecord* pER) :
                                        ptrRR(pRR), ptrER(pER)
   { /* empty*/ }                      
//-----------------------------------------------------------
void annualReport::display()
   {
   cout << "Annual Summary\n--------------\n";
   cout << "Income\n";      
   cout << "\tRent\t\t";           
   rents = ptrRR->getSumOfRents();
   cout << rents << endl;

   cout << "Expenses\n";
   expenses = ptrER->displaySummary();
   cout << "\nBalance\t\t\t" << rents - expenses << endl;
   }
//-----------------------------------------------------------

////////////////methods for class userInterface//////////////
userInterface::userInterface()
   {
   //these reports exist for the life of the program
   ptrTenantList     = new tenantList;
   ptrRentRecord     = new rentRecord;
   ptrExpenseRecord  = new expenseRecord;                    
   }
//-----------------------------------------------------------
userInterface::~userInterface()
   {
   delete ptrTenantList;
   delete ptrRentRecord;
   delete ptrExpenseRecord;
   }
//-----------------------------------------------------------
void userInterface::interact()
   {
   while(true)
      {
      cout << "Enter 'i' to input data, \n"
           << "      'd' to display a report, \n"
           << "      'q' to quit program: ";
      ch = getaChar();
      if(ch=='i')                                // enter data
         {
         cout << "Enter 't' to add tenant, \n"
              << "      'r' to record rent payment, \n"
              << "      'e' to record expense: ";
         ch = getaChar();
         switch(ch)
            {
            //input screens exist only while being used
            case 't': ptrTenantInputScreen = 
               new tenantInputScreen(ptrTenantList);
               ptrTenantInputScreen->getTenant();
               delete ptrTenantInputScreen;
               break;
            case 'r': ptrRentInputScreen =
               new rentInputScreen(ptrTenantList, ptrRentRecord);                                                  
               ptrRentInputScreen->getRent();
               delete ptrRentInputScreen;
               break;                              
            case 'e': ptrExpenseInputScreen = 
               new expenseInputScreen(ptrExpenseRecord);
               ptrExpenseInputScreen->getExpense();
               delete ptrExpenseInputScreen;
               break;
            default: cout << "Unknown input option\n";
               break; 
            }  // end switch    
         }  // end if
      else if(ch=='d')                           // display data
         {
         cout << "Enter 't' to display tenants, \n"
              << "      'r' to display rents\n"
              << "      'e' to display expenses, \n" 
              << "      'a' to display annual report: ";
         ch = getaChar();
         switch(ch)
            {
            case 't': ptrTenantList->display();
               break;
            case 'r': ptrRentRecord->display();
               break;
            case 'e': ptrExpenseRecord->display();
               break;
            case 'a': 
               ptrAnnualReport = new annualReport(ptrRentRecord, 
                                            ptrExpenseRecord);
               ptrAnnualReport->display();
               delete ptrAnnualReport;
               break;
            default: cout << "Unknown display option\n";
               break;
            }  // end switch
         }  // end elseif
      else if(ch=='q')
         return;                               // quit
      else
         cout << "Unknown option. Enter only 'i', 'd' or 'q'\n";
      }  // end while
   }  // end interact()
///////////////////end of file landlord.cpp/////////////////////
