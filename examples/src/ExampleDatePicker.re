open MomentRe;

type action =
  | DateChange(Moment.t);

type state = {
  date: Moment.t
};

let component = ReasonReact.reducerComponent("ExampleDatePicker");

let make = _children => {
  ...component,
  initialState: () => {
    date: momentNow(),
  },
  reducer: (action, state) =>
    switch (action) {
    | DateChange(date) =>
      ReasonReact.Update({date: date})
    },
  render: self =>
    <ReReactDatepicker
      selected=self.state.date
      onChange=(date => self.send(DateChange(date)))
    />,
};
