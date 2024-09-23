//
// Created by aleksey on 23.09.24.
//

#include "affine_transformation.h"


void affine_transformation(
    float const input_coordinate[2],
    float output_coordinate[2],
    float const transformation_matrix[2][2],
    float const linear_bias[2]
    )
{
    for(uint8_t i = 0; i < 2; i++) {

        float temp_coordinate = 0.0;
        for(uint8_t j = 0; j < 2; j++)
            temp_coordinate += transformation_matrix[j][i] * input_coordinate[j];

        output_coordinate[i] = temp_coordinate + linear_bias[i];
    }
}


void calculate_transformation_matrix_2D(float transformation_matrix[2][2], float angle) {

    transformation_matrix[0][0] = cosf(angle);
    transformation_matrix[0][1] = -sinf(angle);
    transformation_matrix[1][0] = sinf(angle);
    transformation_matrix[1][1] = cosf(angle);

}