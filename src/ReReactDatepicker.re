[%bs.raw {|require('react-datepicker/dist/react-datepicker.css')|}];

open MomentRe;

[@bs.obj]
external makeProps :
  (
    ~selected: Moment.t,
    ~onChange: Moment.t => unit,
    ~showTimeSelect: bool=?,
    ~dateFormat: string=?,
    ~includeTimes: array(Moment.t)=?,
    ~injectTimes: array(Moment.t)=?,
    ~minTime: Moment.t=?,
    ~maxTime: Moment.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-datepicker"]
external datePickerAbs : ReasonReact.reactClass = "default";

let datePicker = ReasonReact.statelessComponent("DatePicker");

let make =
    (
      ~selected,
      ~onChange,
      ~showTimeSelect=?,
      ~dateFormat=?,
      ~includeTimes=?,
      ~injectTimes=?,
      ~minTime=?,
      ~maxTime=?,
      children,
    ) => {
  ...datePicker,
  render: _self =>
    ReasonReact.element(
      ReasonReact.wrapJsForReason(
        ~reactClass=datePickerAbs,
        ~props=
          makeProps(
            ~selected,
            ~onChange,
            ~showTimeSelect?,
            ~dateFormat?,
            ~includeTimes?,
            ~injectTimes?,
            ~minTime?,
            ~maxTime?,
            (),
          ),
        children,
      ),
    ),
};
