import React from 'react';
import Button from '@material-ui/core/Button';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogTitle from '@material-ui/core/DialogTitle';

export default function Alert(props) {
  const [open, setOpen] = React.useState(false);

  const handleClickOpen = () => {
    setOpen(true);
  };

  const handleClose = () => {
    setOpen(false);
  };

  return (
    <div>
      <Button 
        onClick={() => {
            props.sendCodeMethod()
            handleClickOpen()
        }}
        style={{
            marginTop: 20,
            backgroundColor: "#777979",
            padding: "18px 36px",
            fontSize: "18px",
            color: "white"
        }}>
          Compile
      </Button>
      <Dialog
        open={open}
        onClose={handleClose}
        aria-labelledby="alert-dialog-title"
        aria-describedby="alert-dialog-description"
      >
        <DialogTitle id="alert-dialog-title">{props.title}</DialogTitle>
        {props.text &&
        <DialogContent>
          <textarea
            rows="10" 
            cols="60" 
          >
            {props.text}
          </textarea>
        </DialogContent>
        }
        <DialogActions>
          <Button onClick={handleClose} color="primary" autoFocus>
            OK
          </Button>
        </DialogActions>
      </Dialog>
    </div>
  );
}
