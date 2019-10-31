#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

bool inbounds(int row, int column, int max_r, int max_c) //test if the input coordinates are within the table limits
{
    if ((row < 0) || (row >= max_r) || (column < 0) || (column >= max_c)) { return false; }
    else { return true; }
}

class Cell
{
  protected:
    bool state;
    int neighbours;
    char id;//= o for normal cell and x for cancer

  public:
    //constructors
    Cell()
    {
        this->state = false;
        this->neighbours = 0;
    };
    Cell(bool state_in)
    {
        this->state = state_in;
    };

    ~Cell(){};


    char get_char()
    {
        return id;
    };

   
    bool get_state()
    {
        return state;
    };

    void neighbours_input(int n)//set neighbours count
    {
        this->neighbours = n;
    };

    void truestate()
    {
        this->state=true;
    };
    
    //virtual functions
     virtual void set_id()
    {
        this->id = 'O';
    };

    virtual void state_update()
    {
        // live or die conditions
        if ( state && (neighbours <= 1) )		// if alive and alone=dies
        {
            this->state = false;
        }
        else if ( state && (neighbours >= 4) )	// overpopulation=dies
        {
            this->state = false;
        }
        else if ( !state && (neighbours == 3) )	// birth
        {															
            this->state = true;
        }
    };
        
};

class Cancer : public Cell //cancer cell derived from Cell
{

    public:
    Cancer() : Cell(){};
    Cancer(bool state_in) : Cell(state_in){};
    ~Cancer(){}; 

    void set_id()
    {
        this->id = 'X';//set the chacter that identifies cancer cell 'x'
    };

    void state_update()//live or die conditions
    {
        
        if ( state && (neighbours <= 1) )// if alive and alone=dies
        {
            this->state = false;
        }
        else if ( state && (neighbours >= 5) )// overpopulation=dies
        {
            this->state = false;
        }
        else if ( !state && (neighbours == 3) )// birth of cancer cell
        {															
            this->state = true;
        }
    };

};  

class Board
{
  private:
    int rows;
    int columns;
    vector<vector<Cell*>> table;//table of objects cells(normal or cancer)
    int time;
    int celltype; //1 for normal and 2 for cancer

  public:
    //constructors
    Board();
    Board(int rows_in, int columns_in);
    ~Board();//destructor

    void seed_cells(int slct, int confl);
    void display();
    void next_state();
    int get_time();
    int get_num_cells();

};

Board::Board()//empty constructor that creates a table with only one normall cell
{
    rows=1;
    columns=1;
    time=0;
    celltype=1;

    Cell* temp_cell = new Cell;
    table[0][0] = temp_cell;

};

Board::Board(int rows_in, int columns_in)//create a normal cells table of the input size
{
    this->rows = rows_in;
    this->columns = columns_in;
    time = 0;
    celltype=1;

    for (int j = 0; j < rows; j++)
    {
        vector<Cell*> temp_column;
        for (int i = 0; i < columns; i++)
        {
            Cell* temp_cell =new Cell;
            temp_column.push_back(temp_cell);  
        }
        table.push_back(temp_column);
    }
};

Board::~Board() { };

void Board::next_state()
    {
        vector< vector<Cell*> > next_table;
        for (int i = 0; i < rows; i++)
        {
            vector<Cell*> column_set;
            for (int j = 0; j < columns; j++)
            {
                int count_neighbours = 0;//neighbours count
                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        if (x*x+y*y)//avoid counting the cell itself (0,0)
                        {
                            if (inbounds(i + x, j + y, rows, columns) )//the tested cordinate has to be on the board
                            {
                                if (table[i + x][j + y]->get_state())
                                {
                                    count_neighbours++;
                                }
                                
                            }
                        }
                    }
                }

                if (celltype - 1)//=1(true) if cancer cell is cellected
                {
                    Cell* temp_cell =new Cancer(table[i][j]->get_state());//create a temporary cell with the state of the current cell frm table
                    column_set.push_back(temp_cell);//place the temporary cell in the temporary table next_table
                    column_set[j]->neighbours_input(count_neighbours);//set the neighbours of the temp cell = neighbours of table[i][j]
                    column_set[j]->state_update();//acording to state and neighbours update state
                }
                else//=0(false) for normal cell
                {
                    Cell* temp_cell =new Cell(table[i][j]->get_state());
                    column_set.push_back(temp_cell);
                    column_set[j]->neighbours_input(count_neighbours);
                    column_set[j]->state_update();
                }
                
            }
            next_table.push_back(column_set);
        }

    //copy the new temporary table in the main one of the board class
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                table.at(i).at(j) = next_table[i][j];
            }
        }
		
        time++;
        next_table.clear();

    };

int Board::get_num_cells()
{
    int active = 0;//active cells
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (table.at(i).at(j)->get_state())
            {
                active++;
            }
        }
    }
    return active;
};

void Board::seed_cells(int slct, int confl)
{
    
    int rand_row = 0;
    int rand_col = 0;
    srand(1);
    this->time=0;
    this->celltype = slct;

    if (slct-1)//if cancer cells are sellected create a table with empty cancer cells
    {
        table.clear();//clear the one created at constructor
        for (int j = 0; j < rows; j++)
        {
            vector<Cell*> temp_column;
            for (int i = 0; i < columns; i++)
            {
                    Cell* temp_cell =new Cancer;
                    temp_column.push_back(temp_cell);   
            }
            table.push_back(temp_column);
        }

    }
    int i = 0;
    while (i < (rows * columns * 0.01 * confl))
    {
        rand_row = rand() % rows;
        rand_col = rand() % columns;
        while (table[rand_row][rand_col]->get_state())//is not aready active
        {
            rand_row = rand() % rows;
            rand_col = rand() % columns;
        };
        table.at(rand_row).at(rand_col)->truestate();
        i++;
    }
};

int Board::get_time()
{
    return time;
};

void Board::display()
{
     
    
    for (int k = 0; k < rows; k++)
    {
        for (int z = 0; z < columns; z++)
        {
            if (table[k][z]->get_state())
            {
                table[k][z]->set_id();//set character
                cout << table[k][z]->get_char();//get character
            }
            else 
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
};

int main()
{
    int selection = 0;  // stores the selection of 1: Cell or 2: Cancer
    int confluence = 0; // stores the percentage of the board filled with cells
    int c;              // stores a character input

    Board board(20, 75); // create a 20 row and 75 column board
    string trash;        // collects useless string data

    system("cls"); // clear the screen to display the welcome screen

    cout << "Welcome to the cell simulator" << endl;
    cout << endl;
    cout << "Select your cell type: (1) normal cells or (2) cancer cells" << endl;

    while ((selection < 1) || (selection > 2))
    {
        cout << ">";
        cin >> selection;
    }

    getline(cin, trash); // a crude way of trashing anything beyond the first input

    cout << "Select the confluence percentage (%)" << endl;
    while ((confluence <= 0) || (confluence > 100))
    {
        cout << ">";
        cin >> confluence;
    }

    getline(cin, trash);

    // seed the board with Cell or Cancer
    board.seed_cells(selection, confluence);
    system("cls"); // clear the screen

    while (c != 'q') // keep running the simulator until 'q' is entered
    {
        system("cls"); // clear the screen (note: omit this when debugging)
        cout << "time: " << board.get_time() << endl;
        cout << "number of cells: " << board.get_num_cells() << endl;
        board.display(); // display the board
        c = cin.get();
        board.next_state(); // get the next state (note: the complex algorithm is in here)
    }
    return 0;
}