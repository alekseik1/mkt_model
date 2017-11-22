//
// Created by aleksei on 22.11.17.
//

#include "MaterialDot.hpp"

MaterialDot::MaterialDot(unsigned char mass,
                     const float initial_coordinates[],
                     const float initial_velocity[],
                     const float initial_acceleration[]) :
        _mass(mass)
{
    _coordinates.reserve(3);
    _velocity.reserve(3);
    _acceleration.reserve(3);
    if(initial_coordinates != nullptr)
        for(int i = 0; i < 3; i++) {
            _coordinates.push_back(initial_coordinates[i]);
        }
    else {
        for(int i = 0; i < 3; i++) {
            _coordinates.push_back(0.0f);
        }
    }
    if(initial_velocity != nullptr)
        for(int i = 0; i < 3; i++) {
            _velocity.push_back(initial_velocity[i]);
        }
    else {
        for(int i = 0; i < 3; i++) {
            _velocity.push_back(0.0f);
        }
    }
    if(initial_acceleration != nullptr)
        for(int i = 0; i < 3; i++) {
            _acceleration.push_back(initial_acceleration[i]);
        }
    else {
        for(int i = 0; i < 3; i++) {
            _acceleration.push_back(0.0f);
        }
    }
}

unsigned char MaterialDot::get_mass() const {
    return _mass;
}

std::vector<float> MaterialDot::get_coordinates() const {
    return _coordinates;
}

void MaterialDot::set_coordinates(float *initial_coordinates) {
    if(initial_coordinates != nullptr)
        for(int i = 0; i < 3; i++) {
            _coordinates[i] = (initial_coordinates[i]);
        }
    else {
        for(int i = 0; i < 3; i++) {
            _coordinates[i] = (0.0f);
        }
    }
}

std::vector<float> MaterialDot::get_velocity() const {
    return _velocity;
}

void MaterialDot::set_velocity(float *initial_velocity) {
    if(initial_velocity != nullptr)
        for(int i = 0; i < 3; i++) {
            _velocity[i] = initial_velocity[i];
        }
    else {
        for(int i = 0; i < 3; i++) {
            _velocity[i] = (0.0f);
        }
    }}

std::vector<float> MaterialDot::get_acceleration() const {
    return _acceleration;
}

void MaterialDot::set_acceleration(float *initial_acceleration) {
    if(initial_acceleration != nullptr)
        for(int i = 0; i < 3; i++) {
            _acceleration[i] = initial_acceleration[i];
        }
    else {
        for(int i = 0; i < 3; i++) {
            _acceleration[i] = (0.0f);
        }
    }
}

void MaterialDot::evolute(float dt) {
    for(int i = 0; i < 3; i++) {
        _coordinates[i] += _velocity[i]*dt + _acceleration[i]*dt*dt/2;
    }
}