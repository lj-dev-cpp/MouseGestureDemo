#ifndef _GESTURE_RECOG_H_
#define _GESTURE_RECOG_H_

#include <vector>
#include <string>
#include <atlstr.h>
#include "MLNet.h"
#include "GestureLearn.h"

typedef std::vector<double> vector_real_t;
typedef std::vector<POINT> path_t;

// Simple winner structure for top results
struct winner
{
    CString name;
    double value;
};

// Gesture recognition structure
struct tGestureRecog
{
    path_t m_path;                // original gesture path
    path_t m_path2;               // normalized/resampled path
    vector_real_t m_angles;       // direction angles
    vector_real_t m_cosines;      // cosine values of angles
    vector_real_t m_sinuses;      // sine values of angles
    vector_real_t m_errors;       // error results
    winner m_winners[3];          // top 3 results

    MLNet m_net;                  // neural network model
    GestureLearn m_learn;         // training interface

    unsigned NUMBER_OF_ANGLES;    // sample count per gesture
    unsigned NUMBER_OF_ANCHOR_POINTS;

    tGestureRecog();
    void Clear();

    // Convert mouse path to normalized form
    void TransformPath(const path_t& src);

    // Extract angle features from path
    void CalcAngles();

    // Recognize current gesture
    CString RecognizeGesture(const std::vector<POINT>& inputPath);

    // Internal utility: normalize path and feed to NN
    void RecognizeBoard();
};

#endif
