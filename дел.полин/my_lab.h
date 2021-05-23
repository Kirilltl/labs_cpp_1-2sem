#ifndef MY_LAB_H
#define ME_LAB_H
bool CheckInput(char s);
int GetCharConvertToInt(const char* Caption, const char* ErrorCaption);
float GetCharConvertToFloat(const char* Caption, const char* ErrorCaption);
void DividePolynomsWithRemainder(float* Poly_1, int PolyLength_1, float* Poly_2, int PolyLength_2, float* Poly_Result, float* Poly_Remainder);
#endif
