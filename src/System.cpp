#include "../include/Objects.h"
#include <iostream>

#ifdef DEBUG_MODE
#define DEBUG_COMMENT(comment) std::cout << "[DEBUG] " << comment << std::endl;
#else
#define DEBUG_COMMENT(comment)
#endif

/// @brief constructor
/// @param automata the Automata of the System
/// @param VariablesDependence automata-variables dependence of the system
System::System(vector<Automata> automata, unordered_map<string, string> &AutomataDependence, unordered_map<string, double *> &automataVariables)
{
    this->automata = automata;
    this->AutomataDependence = AutomataDependence;
    this->automataVariables = automataVariables;
    for (int j = 0; j < this->automata.size(); j++)
    {
        this->automata[j].setAutomataVariables(this->automataVariables);
    }
}

/// @brief return the Automata of the System
/// @return the Automata of the System
vector<Automata> System::getAutomata()
{
    return this->automata;
}

/// @brief return the Automata Dependence
/// @return the automata Automata Dependence
unordered_map<string, string> System::getAutomataDependence()
{
    return this->AutomataDependence;
}

/// @brief to string
ostream &operator<<(ostream &os, System &obj)
{
    os << "\nSystem: \n\n";
    for (Automata s : obj.getAutomata())
    {
        os << s << "\n\n";
    }

    os << "Dependence - Map \n";
    for (auto const &x : obj.getAutomataDependence())
    {
        os << "- " << x.first << " : " << x.second << ";\n";
    }

    return os << "\n\n\n";
}
