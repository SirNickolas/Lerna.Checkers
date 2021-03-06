# Lerna.Checkers

To compile checkers, run `make -j4`. You'll be given tons of warnings, unless they are fixed in
`testlib`. Build should succeed though.


## Available checkers

* `char`, `ichar` — Compares files character by character. Extremely strict, and therefore should
  rarely be used.
* `token`, `itoken`, `exacttoken`, `iexacttoken` — Compares files token by token, ignoring
  whitespace and line breaks.
* `line`, `iline`, `exactline`, `iexactline` — Compares files token by token, ignoring whitespace
  but **not** line breaks.
* `yesno`, `exactyesno` — Compares two sequences of `YES` and `NO`, case-insensitive.
* `int`, `exactint` — Compares two sequences of arbitrary-length signed integral numbers.
* `intline`, `exactintline` — Compares two sequences of arbitrary-length signed integral numbers,
  ignoring whitespace but **not** line breaks.
* `float1` – `float10` — Compares two sequences of real numbers. Absolute or relative error between
  corresponding elements must not exceed 10<sup>-N</sup>.
* `ok` — A stub checker that always returns `OK`.
* `fail` — A stub checker that always returns `FAIL`.

Checkers prefixed with an `i` are case-insensitive.

Normal checkers return `PE` when encountered *EOF* in one file but not in another. Their `exact`
counterparts return `WA` in such case.
