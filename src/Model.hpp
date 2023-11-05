#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "System.hpp"
#include "Flow.hpp"

using namespace std;

class Model {
private:
    vector<Flow*> flows;
    vector<System*> systems;
    vector<vector<double>> history;

public:
    // Constructor
    Model();

    // Iterators
    typedef vector<System *>::iterator systemIterator;
    typedef vector<Flow *>::iterator flowIterator;
    typedef vector<vector<double>>::iterator historyIterator;

    systemIterator beginSystems();
    systemIterator endSystems();   
    flowIterator beginFlows();   
    flowIterator endFlows();
    historyIterator beginHistory();   
    historyIterator endHistory();

    // Destructor
    virtual ~Model();

    // Methods
    void execute(const int timeInitial, const int timeFinal);
    void report();
    void setInitialHistory();

    // Modify the model
    void add(Flow* flow);
    void add(System* system);
    void clearModel();

    Model& operator= (const Model&);
};

#endif
