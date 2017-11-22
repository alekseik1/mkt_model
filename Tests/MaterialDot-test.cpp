//
// Created by aleksei on 22.11.17.
//

#include "catch.hpp"
#include "../MaterialDot.hpp"

TEST_CASE("Empty creating", "[Empty]") {
    MaterialDot md1;
    SECTION("Zero coordinates") {
        float* coord = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(coord[i] == 0.0f);
        }
    }

    SECTION("Zero velocity") {
        float* vel = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(vel[i] == 0.0f);
        }
    }

    SECTION("Zero acceleration") {
        float* accel = md1.get_acceleration();
        for(int i =0; i < 3; i++) {
            CHECK(accel[i] == 0.0f);
        }
    }
}

TEST_CASE("Test with non-default constructor") {
    // DATA
    unsigned char m = 5;
    auto* c = new float[3];
    c[0] = 1.0f; c[1] = 2.3f; c[2] = -12.5f;
    auto* v = new float[3];
    v[0] = -0.123f; v[1] = 1234.9f; v[2] = -8888.2f;
    auto* a = new float[3];
    a[0] = -0.12435234f; a[1] = 123123.0f; a[2] = 613.532f;

    SECTION("Only mass") {
        MaterialDot md1(m);
        CHECK(md1.get_mass() == m);
    }
    SECTION("Mass and coordinates") {
        MaterialDot md1(m, c);
        CHECK(md1.get_mass() == m);
        float* c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }
    SECTION("Mass, coordinates and velocity") {
        MaterialDot md1(m, c, v);
        CHECK(md1.get_mass() == m);
        float* c1 = md1.get_coordinates();
        float* v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
            CHECK(v1[i] == v[i]);
        }

    }
    SECTION("All") {
        MaterialDot md1(m, c, v, a);
        CHECK(md1.get_mass() == m);
        float* c1 = md1.get_coordinates();
        float* v1 = md1.get_velocity();
        float* a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
            CHECK(v1[i] == v[i]);
            CHECK(a1[i] == a[i]);
        }
    }
    delete c, v, a;
}

TEST_CASE("Getters test") {
    // DATA
    unsigned char m = 5;
    auto* c = new float[3];
    c[0] = 1.0f; c[1] = 2.3f; c[2] = -12.5f;
    auto* v = new float[3];
    v[0] = -0.123f; v[1] = 1234.9f; v[2] = -8888.2f;
    auto* a = new float[3];
    a[0] = -0.12435234f; a[1] = 123123.0f; a[2] = 613.532f;

    MaterialDot md1(m, c, v, a);
    SECTION("Mass") {
        CHECK(md1.get_mass() == m);
    }
    SECTION("Coordinates") {
        float* c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }
    SECTION("Velocity") {
        float* v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(v1[i] == v[i]);
        }
    }
    SECTION("Acceleration") {
        float* a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(a1[i] == a[i]);
        }
    }
}

TEST_CASE("Setters test") {
    // DATA
    unsigned char m = 5;
    auto* c = new float[3];
    c[0] = 1.0f; c[1] = 2.3f; c[2] = -12.5f;
    auto* v = new float[3];
    v[0] = -0.123f; v[1] = 1234.9f; v[2] = -8888.2f;
    auto* a = new float[3];
    a[0] = -0.12435234f; a[1] = 123123.0f; a[2] = 613.532f;

    MaterialDot md1;  // Empty by default

    SECTION("Coordinates") {
        md1.set_coordinates(c);
        float* c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }

    SECTION("Velocity") {
        md1.set_velocity(v);
        float* v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(v1[i] == v[i]);
        }
    }

    SECTION("Acceleration") {
        md1.set_acceleration(a);
        float* a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(a1[i] == a[i]);
        }
    }
}