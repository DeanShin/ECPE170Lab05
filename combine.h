#ifndef COMBINE_H
#define COMBINE_H

// Combiner functions with varying algorithm designs
// (but they all accomplish the same tasks!)
void combine1(vec_ptr v, data_t *dest);
void combine2(vec_ptr v, data_t *dest);
void combine3(vec_ptr v, data_t *dest);
void combine4(vec_ptr v, data_t *dest);
void combine5x2(vec_ptr v, data_t *dest);
void combine5x3(vec_ptr v, data_t *dest);
void combine6(vec_ptr v, data_t *dest);

#endif // COMBINE_H
