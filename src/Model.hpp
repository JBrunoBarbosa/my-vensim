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

    // Destructor
    ~Model();

    // Methods
    void execute(int timeInitial, int timeFinal);
    void report();
    void setInitialHistory();

    // Modify the model
    void add(Flow* flow);
    void add(System* system);
    void clearModel();

    // Getters and Setters for t_inicial and t_final
    int getTInicial() const;
    int getTFinal() const;
    void setTInicial(int time);
    void setTFinal(int time);
};

#endif
