[%bs.raw {|require('react-datepicker/dist/react-datepicker.css')|}];

open MomentRe;

[@bs.obj]
external makeProps :
  (
    ~selected: Moment.t,
    ~onChange: Moment.t => unit,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-datepicker"]
external datePickerAbs : ReasonReact.reactClass = "default";
/* external datePickerAbs : ReasonReact.reactClass = "DatePicker"; */

let datePicker = ReasonReact.statelessComponent("DatePicker");

let make =
  (
    ~selected,
    ~onChange,
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
        ()
      ),
        children,
      ),
    ),
};
