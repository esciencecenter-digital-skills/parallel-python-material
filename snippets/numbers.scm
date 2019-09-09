(import (rnrs (6)))

(define zilch "")

(define unit "I")

(define (inc a)
  (string-append a unit))

(define (dec a)
  (substring a 1 (string-length a)))

(define (zilch? a) (string=? a zilch))

(define (unit? a) (string=? a unit))

(trace-define (add a b)
  (if (zilch? a)
      b
      (add (dec a) (inc b))))

(trace-define (bad-mul a b)
  (if (unit? a)
      b
      (add (bad-mul (dec a) b) b)))

(trace-define (madd a b c)
  (if (zilch? a)
      c
      (madd (dec a) b (add b c))))

(trace-define (mul a b) (madd a b zilch))

(display "add\n")
(add "III" "III")

(display "\n\n")
(display "bad-mul\n")
(bad-mul "III" "III")

(display "\n\n")
(display "mul\n")
(mul "III" "III")
