//
// Created by aleksei on 22.11.17.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(unsigned char mass,
                     const float* initial_coordinates,
                     const float* initial_velocity,
                     const float* initial_acceleration) :
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

unsigned char MaterialDot::get_mass() const {
    return _mass;
}

float* MaterialDot::get_coordinates() const {
    return _coordinates;
}

void MaterialDot::set_coordinates(float *_coordinates) {
    MaterialDot::_coordinates = _coordinates;
}

float* MaterialDot::get_velocity() const {
    return _velocity;
}

void MaterialDot::set_velocity(float *_velocity) {
    MaterialDot::_velocity = _velocity;
}

float* MaterialDot::get_acceleration() const {
    return _acceleration;
}

void MaterialDot::set_acceleration(float *_acceleration) {
    MaterialDot::_acceleration = _acceleration;
}

void MaterialDot::evolute(float dt) {
    for(int i = 0; i < 3; i++) {
        _coordinates[i] += _velocity[i]*dt + _acceleration[i]*dt*dt/2;
    }
}


MaterialDot::~MaterialDot() {
    delete _coordinates;
    delete _velocity;
    delete _acceleration;
}