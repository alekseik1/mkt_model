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
         const float* initial_coordinates = nullptr,
         const float* initial_velocity = nullptr,
         const float* initial_acceleration = nullptr);
    virtual ~MaterialDot();


    unsigned char get_mass() const;

    float *get_coordinates() const;

    void set_coordinates(float *_coordinates);

    float *get_velocity() const;

    void set_velocity(float *_velocity);

    float *get_acceleration() const;

    void set_acceleration(float *_acceleration);

    /**
     * Проводит эволюцию материальной точки, соответствующей времени dt
     * @param dt Квант времени, за который происходит эволюция
     */
    void evolute(float dt);

};

#endif //PROJECT_MATERIALDOT_HPP
