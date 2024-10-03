#include "runit/src/runit.h"
#include "../affine_transformation.h"


void test_affine_transformation() {

    float input_coordinate[2];
    float output_coordinate[2];
    float liner_bias[2];
    float transformation_matrix[2][2];

    calculate_transformation_matrix_2D(transformation_matrix, 0);
    runit_fdelta(transformation_matrix[0][0], 1.0, 1e-10);
    runit_fdelta(transformation_matrix[0][1], 0.0, 1e-10);
    runit_fdelta(transformation_matrix[1][0], 0.0, 1e-10);
    runit_fdelta(transformation_matrix[1][1], 1.0, 1e-10);

    liner_bias[0] = 2;
    liner_bias[1] = 1;

    input_coordinate[0] = 2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 4.0, 1e-10);
    runit_fdelta(output_coordinate[1], 5.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], 5.0, 1e-10);

    input_coordinate[0] = 2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 4.0, 1e-10);
    runit_fdelta(output_coordinate[1], -3.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], -3.0, 1e-10);


    liner_bias[0] = -2;
    liner_bias[1] = 1;

    input_coordinate[0] = 2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], 5.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], -4.0, 1e-10);
    runit_fdelta(output_coordinate[1], 5.0, 1e-10);

    input_coordinate[0] = 2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], -3.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], -4.0, 1e-10);
    runit_fdelta(output_coordinate[1], -3.0, 1e-10);


    liner_bias[0] = 2;
    liner_bias[1] = -1;

    input_coordinate[0] = 2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 4.0, 1e-10);
    runit_fdelta(output_coordinate[1], 3.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], 3.0, 1e-10);

    input_coordinate[0] = 2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 4.0, 1e-10);
    runit_fdelta(output_coordinate[1], -5.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], -5.0, 1e-10);


    liner_bias[0] = -2;
    liner_bias[1] = -1;

    input_coordinate[0] = 2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], 3.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = 4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], -4.0, 1e-10);
    runit_fdelta(output_coordinate[1], 3.0, 1e-10);

    input_coordinate[0] = 2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], 0.0, 1e-10);
    runit_fdelta(output_coordinate[1], -5.0, 1e-10);

    input_coordinate[0] = -2;
    input_coordinate[1] = -4;
    affine_transformation(input_coordinate, output_coordinate, transformation_matrix, liner_bias);
    runit_fdelta(output_coordinate[0], -4.0, 1e-10);
    runit_fdelta(output_coordinate[1], -5.0, 1e-10);


    calculate_transformation_matrix_2D(transformation_matrix, M_PI/36);
    runit_fdelta(transformation_matrix[0][0], 0.9961946981, 1e-5);
    runit_fdelta(transformation_matrix[0][1], -0.0871557427, 1e-5);
    runit_fdelta(transformation_matrix[1][0], 0.0871557427, 1e-5);
    runit_fdelta(transformation_matrix[1][1], 0.9961946981, 1e-5);


    
}


int main()
{
    test_affine_transformation();
    runit_report();
    return runit_at_least_one_fail;
}