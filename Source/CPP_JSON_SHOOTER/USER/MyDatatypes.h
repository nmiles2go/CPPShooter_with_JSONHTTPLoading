// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
 // One defined object TYPE (RedBox / BlueBox / GreenBox)
struct FMyTypeDef
{
    FName Name;           // types[i].name
    FLinearColor Color;   // types[i].color [0..255,0..255,0..255] -> normalized 0..1
    int32 Health = 1;     // types[i].health
    int32 Score = 0;     // types[i].score
};

// One OBJECT instance entry (points to a type + transform)
struct FMyObjectEntry
{
    FName Type;       // objects[i].type

    // objects[i].transform
    FVector Location; // xyz in centimeters
    FVector Scale;    // xyz scale
    // rotation is roll, pitch, yaw (degrees) in the JSON
    // UE FRotator is Pitch, Yaw, Roll — we'll map carefully when we build FTransform
    FVector RotationRPY; // (R, P, Y) in degrees as given
};