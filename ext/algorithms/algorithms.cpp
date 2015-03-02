#include "algorithms.h"

// Include the Ruby headers and goodies
// TODO: Hide this in c++/use forward declarations if needed
#include <ruby.h>

// Prototype for the initialization method - Ruby calls this, not you
void Init_algorithms();

#include <string>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// http://phrogz.net/programmingruby/ext_ruby.html
///////////////////////////////////////////////////////////////////////////////

/*
#define T_NONE   RUBY_T_NONE
#define T_NIL    RUBY_T_NIL
#define T_OBJECT RUBY_T_OBJECT
#define T_CLASS  RUBY_T_CLASS
#define T_ICLASS RUBY_T_ICLASS
#define T_MODULE RUBY_T_MODULE
#define T_FLOAT  RUBY_T_FLOAT
#define T_STRING RUBY_T_STRING
#define T_REGEXP RUBY_T_REGEXP
#define T_ARRAY  RUBY_T_ARRAY
#define T_HASH   RUBY_T_HASH
#define T_STRUCT RUBY_T_STRUCT
#define T_BIGNUM RUBY_T_BIGNUM
#define T_FILE   RUBY_T_FILE
#define T_FIXNUM RUBY_T_FIXNUM
#define T_TRUE   RUBY_T_TRUE
#define T_FALSE  RUBY_T_FALSE
#define T_DATA   RUBY_T_DATA
#define T_MATCH  RUBY_T_MATCH
#define T_SYMBOL RUBY_T_SYMBOL
#define T_RATIONAL RUBY_T_RATIONAL
#define T_COMPLEX RUBY_T_COMPLEX
#define T_UNDEF  RUBY_T_UNDEF
#define T_NODE   RUBY_T_NODE
#define T_ZOMBIE RUBY_T_ZOMBIE
#define T_MASK   RUBY_T_MASK
//*/

namespace {
    // Defining a space for information and references about the module to be stored internally
    static VALUE AlgorithmsModule = Qnil;

    // Prototype for our method 'test'
    VALUE algorithms_method_answer_42(VALUE self);
    VALUE algorithms_method_test(VALUE self);
    VALUE algorithms_method_fact(VALUE self, VALUE rb_int);

    // Our 'answer_42' method.. it simply returns a value of '10' for now.
    VALUE algorithms_method_answer_42(VALUE self) {
        const int x = 42;
        return INT2NUM(x);
    }

    // Our 'test' method.. it simply returns a value of '10' for now.
    VALUE algorithms_method_test(VALUE self) {
        // int x = 10;
        // return INT2NUM(x);

        std::string msg = "Hello World!";
        return rb_str_new2(msg.c_str());
    }

    // Our 'fact' method ..
    VALUE algorithms_method_fact(VALUE self, VALUE rb_int) {
        Check_Type(rb_int, T_FIXNUM);

        unsigned int val = FIX2UINT(rb_int);

        unsigned long long res = 1;
        for(unsigned int i = 1; i <= val; i++) {
            res *= i;
        }

        return INT2NUM(res);
    }
}; // anonymous namespace

///////////////////////////////////////////////////////////////////////////////
// The initialization method for this module
///////////////////////////////////////////////////////////////////////////////
extern "C" void Init_algorithms() {
	AlgorithmsModule = rb_define_module("Algorithms");

	rb_define_method(AlgorithmsModule, "answer42", (VALUE(*)(ANYARGS))algorithms_method_answer_42, 0);

	rb_define_method(AlgorithmsModule, "test", (VALUE(*)(ANYARGS))algorithms_method_test, 0);

	rb_define_method(AlgorithmsModule, "fact", (VALUE(*)(ANYARGS))algorithms_method_fact, 1);
}