open Jest;

describe(
  "99 problems",
  () => {
    open Expect;
    test("p01_1", () => expect(Pr.last_element_01([12, 21, 47])) |> toEqual(Some(47)));
    test("p01_2", () => expect(Pr.last_element_01([])) |> toBe(None));
    test("p02_1", () => expect(Pr.last_two_02([12, 21, 47]) |> toEqual(Some((21, 47)))))
    /* test("p02_2", () => expect(Pr.last_two_02(["12", "21", "47"]) |> toEqual(Some(("21", "47")))));
       test("p02_3", () => expect(Pr.last_two_02([12]) |> toBe(None))) */
  }
);