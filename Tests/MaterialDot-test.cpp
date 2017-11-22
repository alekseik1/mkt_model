//
// Created by aleksei on 22.11.17.
//

#include "catch.hpp"
#include "../MaterialDot.hpp"

TEST_CASE("Empty creating", "[Empty]") {
    MaterialDot md1;
    SECTION("Zero coordinates") {
        std::vector<float> coord = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(coord[i] == 0.0f);
        }
    }

    SECTION("Zero velocity") {
        std::vector<float> vel = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(vel[i] == 0.0f);
        }
    }

    SECTION("Zero acceleration") {
        std::vector<float> accel = md1.get_acceleration();
        for(int i =0; i < 3; i++) {
            CHECK(accel[i] == 0.0f);
        }
    }
}

TEST_CASE("Test with non-default constructor") {
    // DATA
    unsigned char m = 5;
    float c[] = {1.0f, 2.3f, -12.5f};
    float v[] = {-0.123f, 1234.9f, -8123.4f};
    float a[] = {-0.1232145f, 1231235.0f, 6547563.3432423f};

    SECTION("Only mass") {
        MaterialDot md1(m);
        CHECK(md1.get_mass() == m);
    }
    SECTION("Mass and coordinates") {
        MaterialDot md1(m, c);
        CHECK(md1.get_mass() == m);
        std::vector<float> c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }
    SECTION("Mass, coordinates and velocity") {
        MaterialDot md1(m, c, v);
        CHECK(md1.get_mass() == m);
        std::vector<float> c1 = md1.get_coordinates();
        std::vector<float> v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
            CHECK(v1[i] == v[i]);
        }

    }
    SECTION("All") {
        MaterialDot md1(m, c, v, a);
        CHECK(md1.get_mass() == m);
        std::vector<float> c1 = md1.get_coordinates();
        std::vector<float> v1 = md1.get_velocity();
        std::vector<float> a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
            CHECK(v1[i] == v[i]);
            CHECK(a1[i] == a[i]);
        }
    }
}

TEST_CASE("Getters test") {
    // DATA
    unsigned char m = 5;
    float c[] = {1.0f, 2.3f, -12.5f};
    float v[] = {-0.123f, 1234.9f, -8123.4f};
    float a[] = {-0.1232145f, 1231235.0f, 6547563.3432423f};

    MaterialDot md1(m, c, v, a);
    SECTION("Mass") {
        CHECK(md1.get_mass() == m);
    }
    SECTION("Coordinates") {
        std::vector<float> c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }
    SECTION("Velocity") {
        std::vector<float> v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(v1[i] == v[i]);
        }
    }
    SECTION("Acceleration") {
        std::vector<float> a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(a1[i] == a[i]);
        }
    }
}

TEST_CASE("Setters test") {
    // DATA
    unsigned char m = 5;
    float c[] = {1.0f, 2.3f, -12.5f};
    float v[] = {-0.123f, 1234.9f, -8123.4f};
    float a[] = {-0.1232145f, 1231235.0f, 6547563.3432423f};

    MaterialDot md1;  // Empty by default

    SECTION("Coordinates") {
        md1.set_coordinates(c);
        std::vector<float> c1 = md1.get_coordinates();
        for(int i = 0; i < 3; i++) {
            CHECK(c1[i] == c[i]);
        }
    }

    SECTION("Velocity") {
        md1.set_velocity(v);
        std::vector<float> v1 = md1.get_velocity();
        for(int i = 0; i < 3; i++) {
            CHECK(v1[i] == v[i]);
        }
    }

    SECTION("Acceleration") {
        md1.set_acceleration(a);
        std::vector<float> a1 = md1.get_acceleration();
        for(int i = 0; i < 3; i++) {
            CHECK(a1[i] == a[i]);
        }
    }
}