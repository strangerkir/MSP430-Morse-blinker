#ifndef SIGNALS_H
#define SIGNALS_H

/**
 * Long signal
 */
void dah(void);

/**
 * Short signal
 */
void dit(void);

/**
 * Short pause. Used between dits and dahs inside one character
 */
void intraCharacterSpace(void);

/**
 * Middle pause. Used between characters inside word.
 */
void characterSpace(void);

/**
 * Long pause. Used between words.
 */
void wordSpace(void);

#endif
