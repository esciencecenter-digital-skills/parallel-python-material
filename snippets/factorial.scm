(import (rnrs (6)))

(trace-define (fac n)
  (if (zero? n)
      1
      (* n (fac (- n 1)))))

(trace-define (fac-tc n)
  (trace-let loop ((m n)
                   (x 1))
    (if (zero? m)
        x
        (loop (- m 1) (* x m)))))

(display "naive factorial:\n")
(fac 3)
(display "\ntail-recursive factorial:\n")
(fac-tc 3)

