/**
 * @class SystemImpl
 * @brief Classe que implementa System.
 */
#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "System.hpp"

class SystemImpl: public System {
protected:
    std::string name;      
    double value;     

public:
    SystemImpl(const std::string name = "", const double value = 0.0);
    SystemImpl(const System* other);
    virtual ~SystemImpl();

    void setName(const std::string name) override;
    void setValue(const double value) override;
    std::string getName() const override;
    double getValue() const override;
    System& operator=(const System& other);
    System* clone() const override;
};

#endif
