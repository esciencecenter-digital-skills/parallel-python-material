(let* ((expr1 '(+ 6 7))
       (expr2 (cons '* (cdr expr1))))
  (display expr1) (newline)
  (display " => ") (display (eval expr1)) (newline)
  (display expr2) (newline)
  (display " => ") (display (eval expr2)) (newline))

