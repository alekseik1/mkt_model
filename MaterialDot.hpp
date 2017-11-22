//
// Created by aleksei on 22.11.17.
//

#ifndef PROJECT_MATERIALDOT_HPP
#define PROJECT_MATERIALDOT_HPP

#include <vector>
/**
 * Класс материальной точки -- основного объекта динамики
 */
class MaterialDot {
private:
    unsigned char _mass;
    float* _coordinates;
    float* _velocity;
    float* _acceleration;

public:

    /**
     * Конструктор материальной точки.
     * @param mass Масса точки
     * @param initial_coordinates Массив из float[3], содержащий начальные координаты. По умолчанию нули
     * @param initial_velocity Массив из float[3], содержащий начальную скорость. По умолчанию нули
     * @param initial_acceleration Массив из float[3], содержащий начальные ускорения. По умолчанию нули
     */
    explicit MaterialDot(unsigned char mass = 2,
         float* initial_coordinates = nullptr,
         float* initial_velocity = nullptr,
         float* initial_acceleration = nullptr) :
            _mass(mass)
    {
        _coordinates = new float(3);
        _velocity = new float(3);
        _acceleration = new float(3);
        // TODO: Здесь идет опасное присваивание! Надо будет сделать потом проверки
        if(initial_coordinates != nullptr)
            for(int i = 0; i < 3; i++) {
                _coordinates[i] = initial_coordinates[i];
            }
        else {
            _coordinates[0] = 0.0f;
            _coordinates[1] = 0.0f;
            _coordinates[2] = 0.0f;
        }
        if(initial_velocity != nullptr)
            for(int i = 0; i < 3; i++) {
                _velocity[i] = initial_velocity[i];
            }
        else {
            _velocity[0] = 0.0f;
            _velocity[1] = 0.0f;
            _velocity[2] = 0.0f;
        }
        if(initial_acceleration != nullptr)
            for(int i = 0; i < 3; i++) {
                _acceleration[i] = initial_acceleration[i];
            }
        else {
            _acceleration[0] = 0.0f;
            _acceleration[1] = 0.0f;
            _acceleration[2] = 0.0f;
        }
    }

    virtual ~MaterialDot() {
        delete _coordinates;
        delete _velocity;
        delete _acceleration;
    }


    unsigned char get_mass() const {
        return _mass;
    }

    float *get_coordinates() const {
        return _coordinates;
    }

    void set_coordinates(float *_coordinates) {
        MaterialDot::_coordinates = _coordinates;
    }

    float *get_velocity() const {
        return _velocity;
    }

    void set_velocity(float *_velocity) {
        MaterialDot::_velocity = _velocity;
    }

    float *get_acceleration() const {
        return _acceleration;
    }

    void set_acceleration(float *_acceleration) {
        MaterialDot::_acceleration = _acceleration;
    }

};

#endif //PROJECT_MATERIALDOT_HPP
