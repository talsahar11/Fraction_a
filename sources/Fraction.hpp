#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
namespace ariel {
    class Fraction {
    private:
        int numerator, denominator;
        float value;

        int findGCD(int numerator, int denominator) {
            return 0;
        }

        Fraction reduce_form(Fraction fraction) {
            return Fraction(0, 0);
        }

    public:
        explicit Fraction(int numerator = 0, int denominator = 0): numerator(numerator), denominator(denominator) {}
        Fraction(Fraction& f) {}
        int getNumerator(){
            return 0 ;
        }
        int getDenominator(){
            return 0 ;
        }

        Fraction operator+(const Fraction& other) {
            return Fraction(1, 1);
        }

        friend Fraction operator+(const Fraction& f, const float value) {
            return Fraction(1, 1);
        }

        friend Fraction operator+(const float value, const Fraction& fraction){
            return Fraction(1,1) ;
        }

        Fraction operator-(const Fraction& other) {
            return Fraction(1, 1);
        }

        friend Fraction operator-(const Fraction& f, const float value) {
            return Fraction(1, 1);
        }

        friend Fraction operator-(const float value, const Fraction& fraction){
            return Fraction(1,1) ;
        }


        Fraction operator*(const Fraction& other){
            return Fraction(1,1) ;
        }

        friend Fraction operator*(const Fraction& f, const float value){
            return Fraction(1,1) ;
        }

        friend Fraction operator*(const float value, const Fraction& fraction){
            return Fraction(1,1) ;
        }

        Fraction operator/(const Fraction& other) {
            return Fraction(0, 0);
        }

        friend Fraction operator/(const Fraction& f, const float value) {
            return Fraction(0, 0);
        }

        friend Fraction operator/(const float value, const Fraction& fraction){
            return Fraction(0,0) ;
        }

        bool operator==(const Fraction& other) {
            return false;
        }

        friend bool operator==(const Fraction& f, const float value) {
            return false;
        }

        friend bool operator==(const float value, const Fraction& f) {
            return false;
        }

        bool operator>=(const Fraction& other) {
            return false;
        }

        friend bool operator>=(const Fraction& f, const float value) {
            return false;
        }

        friend bool operator>=(const float value, const Fraction& f) {
            return false;
        }

        bool operator<=(const Fraction& other) {
            return false;
        }

        friend bool operator<=(const Fraction& f, const float value) {
            return false;
        }

        friend bool operator<=(const float value, const Fraction& f) {
            return false;
        }

        bool operator>(const Fraction& other) {
            return false;
        }

        friend bool operator>(const Fraction& f, const float value) {
            return false;
        }

        friend bool operator>(const float value, const Fraction& f) {
            return false;
        }

        bool operator<(const Fraction& other) {
            return false;
        }

        friend bool operator<(const Fraction& f, const float value) {
            return false;
        }

        friend bool operator<(const float value, const Fraction& f) {
            return false;
        }

        Fraction &operator++() {
            return *this ;
        }

        Fraction &operator--() {
            return *this ;
        }

        Fraction operator++(int) {
            return Fraction(0, 0);
        }

        Fraction operator--(int) {
            return Fraction(0, 0);
        }

        friend std::ostream& operator<<(std::ostream &os, const Fraction &f) {
            os << f.numerator << "/" << f.denominator ;
            return os;
        }

        friend std::istream& operator>>(std::istream &in, Fraction &f) {
            return in;
        }
    };


}
#endif