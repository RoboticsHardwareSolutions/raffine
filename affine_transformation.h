//
// Created by aleksey on 23.09.24.
//

#ifndef AFFINE_TRANSFORMATION_H
#define AFFINE_TRANSFORMATION_H


#include <stdint.h>
#include <math.h>


/// Calculate cordinate in old frmae using affine transformation:
///     X = dX + MX'
/// where   X - coordinates in old frame (output function)
///         dX - liner_bias
///         M - transfomation matrix
///         X' - coordinates in new frame
/// @param input_coordinate array of coordinates 2x1 size in new coordinate frame
/// @param output_coordinate array of coordinates 2x1 size in old coordinate frame
/// @param transformation_matrix transfomation matrix array of old to new coordinate frame 2x2 size
/// @param linear_bias linear bias array of new coordinate frame calculated in old coordinate frame 2x1 size
void affine_transformation(
    float const input_coordinate[2],
    float output_coordinate[2],
    float const transformation_matrix[2][2],
    float const linear_bias[2]
    );


/// Calculate transformation matrix using angle between frames.\n
/// The angle is measured from the axis of the old coordinate frame
/// to the same axis of the new frame.\n
/// Positive direction -- Clockwise
/// @param transformation_matrix array of ttransformation matrix
/// @param angle angle between cordinate frames
void calculate_transformation_matrix_2D(
    float transformation_matrix[2][2],
    float angle
    );

#endif //AFFINE_TRANSFORMATION_H
