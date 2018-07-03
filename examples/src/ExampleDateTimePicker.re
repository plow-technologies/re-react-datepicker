open MomentRe;

type action =
  | DateChange(Moment.t);

type state = {
  date: Moment.t
};

let component = ReasonReact.reducerComponent("ExampleTimeDatePicker");

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
      showTimeSelect=true
      timeFormat="HH:mm"
      timeIntervals=15
      dateFormat="LLL"
      timeCaption="time"
    />,
};
