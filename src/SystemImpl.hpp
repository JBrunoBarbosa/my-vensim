/**
 * @class SystemImpl
 * @brief Classe que implementa System.
 */
#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "System.hpp"
#include "HandleBody.hpp"

class SystemImpl: public Body {
protected:
    std::string name;      
    double value;     

public:
    SystemImpl(const std::string name = "", const double value = 0.0);
    SystemImpl(const System* other);
    virtual ~SystemImpl();

    void setName(const std::string name);
    void setValue(const double value);
    std::string getName() const;
    double getValue() const;
    SystemImpl& operator=(const SystemImpl& other);
};

#endif
